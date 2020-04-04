#include <sstream>
#include <iostream>

#include <boost/asio.hpp>
#include "controller.h"
#include "server.h"
#include "rpc_meta.pb.h"

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

Server::Server() {}
Server::~Server() {}

int Server::Start(std::string ip, int port) {
	boost::asio::io_service io;
	boost::asio::ip::tcp::endpoint ep(
			boost::asio::ip::address::from_string(ip), port);
	boost::asio::ip::tcp::acceptor acceptor(io, ep);

	while (true) {
		auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io);
		acceptor.accept(*socket);
		
		std::cout << "notice: recv from client" 
			<< socket->remote_endpoint().address() << std::endl;

		char rpc_meta_buf[sizeof(int)];
		socket->receive(boost::asio::buffer(rpc_meta_buf));
		int rpc_meta_size = *(int *)rpc_meta_buf;
		std::vector<char> meta_buf(rpc_meta_size, 0);
		socket->receive(boost::asio::buffer(meta_buf));
		srpc::RpcMeta rpc_meta;
		rpc_meta.ParseFromString(std::string(&meta_buf[0], meta_buf.size()));


		std::vector<char> request_data(rpc_meta.data_size(), 0);
		socket->receive(boost::asio::buffer(request_data));

		std::cout << "----------------------" << std::endl;
		std::cout << "recev info service" << rpc_meta.service_id() << std::endl;
		std::cout << "recev info method" << rpc_meta.method_id() << std::endl;
		std::cout << "recev info data size" << rpc_meta.data_size() << std::endl;
		std::cout << "recev info meta size" << rpc_meta_size << std::endl;
		std::copy(request_data.begin(), 
				request_data.end(),
				std::ostream_iterator<char>(std::cout, ""));
//		std::cout << "recev info data" << << std::endl;

		std::cout << "----------------------" << std::endl;

		ProcRpcMsg(rpc_meta.service_id(), rpc_meta.method_id(), 
				std::string(&request_data[0], request_data.size()), socket);
	}
	return 0;
}

int Server::ProcRpcMsg(const std::string &service_id, 
		const std::string &method_id,
		const std::string &serialized_data, 
		const std::shared_ptr<boost::asio::ip::tcp::socket> socket) {
	auto service = services_[service_id].service;
	auto mdescriptor = services_[service_id].mdescriptor[method_id];

	auto recv_msg = service->GetRequestPrototype(mdescriptor).New();
	auto resp_msg = service->GetResponsePrototype(mdescriptor).New();

	recv_msg->ParseFromString(serialized_data);

	auto done = ::google::protobuf::NewCallback(
			this, &Server::OnCallbackDone, resp_msg, socket);
	Controller cntl;
	service->CallMethod(mdescriptor, &cntl, recv_msg, resp_msg, done);
	return 0;
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
		const std::shared_ptr<boost::asio::ip::tcp::socket> socket) {
	int s = resp_msg->ByteSizeLong();
	std::string serialized_str;
	serialized_str.insert(0, std::string((const char *)&s, sizeof(int)));
	resp_msg->AppendToString(&serialized_str);

	socket->send(boost::asio::buffer(serialized_str));
}

