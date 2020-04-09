#include <thread>
#include <sstream>
#include <iostream>
#include <sys/epoll.h>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

#include "controller.h"
#include "server.h"
#include "rpc_meta.pb.h"


std::map<std::string, Server::ServiceInfo> Server::services_;

void SetNonblocking(int sock_fd) {
	int opts = fcntl(sock_fd, F_GETFL);
	if (opts < 0) {
		perror("fcntl(F_GETFL) failed.");
		return ;
	}

	opts |= O_NONBLOCK;
	if (fcntl(sock_fd, F_SETFL, opts) < 0) {
		perror("fcntl(F_SETFL) failed.");
		return ;
	}
}


Server::Server():listen_fd_(-1), epfd_(-1) {
}
Server::~Server() {
	Close();
}

int Server::Close() {
	if (0 <= listen_fd_) {
		while (close(listen_fd_) && errno == EINTR) {
		}
		listen_fd_ = -1;
	}
	return 0;
}

int Server::Start(std::string ip, int port) {
	if ((listen_fd_ = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("create socket failed.");
		return -1;
	}

	SetNonblocking(listen_fd_);

	struct sockaddr_in local;
	bzero(&local, sizeof(local));
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = inet_addr(ip.c_str());
	local.sin_port = htons(port);

	if (bind(listen_fd_, (struct sockaddr *) &local, sizeof(local)) < 0) {
		perror("bind failed.");
		return -1;
	}

	listen(listen_fd_, 1024);

	const int MAX_EVENTS = 1024;
	epfd_ = epoll_create(MAX_EVENTS);
	if (epfd_ == -1) {
		perror("epoll_create failed.");
		return -1;
	}

	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = listen_fd_;
	if (epoll_ctl(epfd_, EPOLL_CTL_ADD, listen_fd_, &ev) < 0) {
		perror("epoll ctl failed.");
		return -1;
	}

	int accept_num = 0;
	while (true) {
		struct epoll_event events[MAX_EVENTS];
		int num_fd = epoll_wait(epfd_, events, MAX_EVENTS, -1);
//		printf("epoll wait event num: %d\n", num_fd); 
		if (num_fd < 0) {
			perror("epool_warit failed.");
			return -1;
		}
		
		for (int i = 0; i < num_fd; ++i) {
			if (events[i].data.fd == listen_fd_) {
				printf("accept %d\n", ++accept_num);
				fflush(stdout);
				//accept
				if (OnNewConnection()) {
					//
				}
			} else if (events[i].events & EPOLLIN) {
				//read
				int sockfd = events[i].data.fd;
				std::thread th(Server::OnNewMessage, sockfd);
				th.join();
			} else if (events[i].events & EPOLLOUT) {
				//write
			}
		}
	}
	return 0;
}

int Server::OnNewConnection() {
	//accept
	struct sockaddr_in remote_addr;
	socklen_t sock_len; 
	int conn_fd = 
		accept(listen_fd_, (struct sockaddr *)&remote_addr, &sock_len);
	if (conn_fd < 0) {
		perror("accept");
		return -1;
	}
	printf("accept a connection from client: %s\n",
			 inet_ntoa(remote_addr.sin_addr));
	//create READ event
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = conn_fd;
	if (epoll_ctl(epfd_, EPOLL_CTL_ADD, conn_fd, &ev) < 0) {
		close(conn_fd);
		perror("epoll ctl failed.");
		return -1;
	}
	return 0;
}

int RecvMsg(int fd, char *buf, int len) {
	if (buf == nullptr) {
		return -1;
	}

	int num_read = 0;
	do {
		num_read = recv(fd, buf, len, MSG_WAITALL);
		if (num_read < 0) {
			if (errno == EAGAIN) { break; }
			if (EINTR == errno) { continue; }
			//TODO del epoll event for fd
			return -1;
		} 
		break;
	}  while(true);
	return num_read;
}

void Server::OnNewMessage(const int fd) {
	int rpc_meta_len;
	int num_read = RecvMsg(fd, (char *)&rpc_meta_len, sizeof(int));
	if (num_read < 0) {
		perror("recv error\n");
		close(fd);
		exit(-1);
	} else if (num_read == 0) { return ; }
	printf("recv meta size : %d\n", rpc_meta_len);

	std::vector<char> meta_buf(rpc_meta_len, 0);
	num_read = RecvMsg(fd, (char *)&(meta_buf[0]), rpc_meta_len);
	if (num_read < 0) {
		perror("recv error\n");
		close(fd);
		exit(-1);
	} else if (num_read == 0) { return ; }
	srpc::RpcMeta rpc_meta;
	rpc_meta.ParseFromString(std::string(&(meta_buf[0]), meta_buf.size()));

	printf("recv data size : %d\n", rpc_meta.data_size());
	std::vector<char> request_data(rpc_meta.data_size(), 0);
	//!TODO if data_size() == 0, recv will be block here.
	num_read = RecvMsg(fd, (char *)&(request_data[0]), rpc_meta.data_size());
	if (num_read < 0) {
		perror("recv error\n");
		close(fd);
		exit(-1);
	} else if (num_read == 0) { return ; }

//	printf("method: %s.%s\n", rpc_meta.service_id().c_str(),
//			rpc_meta.method_id().c_str());

	auto service = services_[rpc_meta.service_id()].service;
	auto mdescriptor = 
		services_[rpc_meta.service_id()].mdescriptor[rpc_meta.method_id()];

	auto recv_msg = service->GetRequestPrototype(mdescriptor).New();
	auto resp_msg = service->GetResponsePrototype(mdescriptor).New();

	recv_msg->ParseFromString(std::string(&request_data[0], request_data.size()));

	auto done = ::google::protobuf::NewCallback(
			&Server::OnCallbackDone, resp_msg, fd);
	Controller cntl;
	
	//process message
	service->CallMethod(mdescriptor, &cntl, recv_msg, resp_msg, done);
	close(fd);
	return ;
}

int Server::AddService(google::protobuf::Service *service, bool ownership) {
	std::string method_id;
	ServiceInfo service_info;

	const ::google::protobuf::ServiceDescriptor *sdescriptor = 
		service->GetDescriptor();
	service_info.service = service;
	for (size_t i = 0; i < sdescriptor->method_count(); ++i) {
		method_id = sdescriptor->method(i)->name();
		service_info.mdescriptor[method_id] = sdescriptor->method(i);
	}
	services_[sdescriptor->name()] = service_info;

	return 0;
}


void Server::OnCallbackDone(::google::protobuf::Message* resp_msg,
		const int fd) {
	int s = resp_msg->ByteSizeLong();
	int nsend = send(fd, (char *)&s, sizeof(int), MSG_WAITALL);
	resp_msg->SerializeToFileDescriptor(fd);
	return ;
}

