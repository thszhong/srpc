
#include <iostream>
#include <sstream>
#include <google/protobuf/message.h>
#include "channel.h"
#include "rpc_meta.pb.h"

Channel::Channel()  {
	fd_ = -1;
}

Channel::~Channel() {
	Close();
}

int Channel::Close() {
	if (0 <= fd_) {
		while(close(fd_) && (EINTR == errno)) {
			//
		}
		fd_ = -1;
	}
	return 0;
}

int Channel::Init(std::string ip, int port) {
	ip_ = ip;
	port_ = port;
	struct sockaddr_in svr_addr;
	bzero(&svr_addr, sizeof(svr_addr));
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_port = htons(port_);
	svr_addr.sin_addr.s_addr = inet_addr(ip_.c_str());

	fd_ = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_ < 0) {
		perror("create socket failed.");
		return -1;
	}
	int ret = connect(fd_, (struct sockaddr *)&svr_addr, sizeof(svr_addr));
	if (ret < 0) {
		perror("connect fail.");
		return -1;
	}

	return 0;
}

void Channel::CallMethod(const ::google::protobuf::MethodDescriptor *method,
		::google::protobuf::RpcController *controller,
		const ::google::protobuf::Message *request,
		::google::protobuf::Message *response,
		::google::protobuf::Closure *done) {
	std::string data_str;
	request->SerializeToString(&data_str);

	srpc::RpcMeta meta;
	meta.set_service_id(method->service()->name());
	meta.set_method_id(method->name());
	meta.set_data_size(data_str.size());
	meta.set_call_id();
	std::string meta_str;
	meta.SerializeToString(&meta_str);

	int meta_size = meta_str.size();
	std::string serialized_str;
	serialized_str.insert(0, std::string((const char *)&meta_size, sizeof(int)));
	serialized_str += meta_str;
	serialized_str += data_str;

//  std::cout << "----------------------" << std::endl;
//	std::cout << "send info service " << meta.service_id() << std::endl;
//	std::cout << "send info method " << meta.method_id() << std::endl;
	std::cout << "send info meta size " << meta_str.size() << std::endl;
	std::cout << "send info data size " << meta.data_size() << std::endl;

	std::cout << "client send size " << serialized_str.size() << std::endl;
	int nsend = send(fd_, 
			serialized_str.c_str(), serialized_str.size(),
			MSG_WAITALL);
	if (nsend == serialized_str.size()) {
		std::cout << "client send success." << std::endl;
	} else {
		std::cout << "client send status " 
			<< nsend << " / " << serialized_str.size() << std::endl;
		close(fd_);
		return ;
	}

	int resp_data_len = 0; 
	do {
		int nread = recv(fd_, (char *)&resp_data_len, sizeof(int), MSG_WAITALL);
		if (nread < 0) {
			if (EINTR == errno || EAGAIN == errno) {
				std::cout << "continue" << std::endl;
				continue;
			} else {
				//close socket
				close(fd_);
				return ;
			}
		} else {
			break;
		}
	} while(true);
	std::cout << "recev data len" << resp_data_len << std::endl;
	std::vector<char> resp_buf(resp_data_len, 0);
	recv(fd_, (char *)&resp_buf[0], resp_data_len, MSG_WAITALL);
//	std::cout << "recev data " << resp_buf << std::endl;
	response->ParseFromString(std::string(&resp_buf[0], resp_buf.size()));

	close(fd_);
	return ;
}
