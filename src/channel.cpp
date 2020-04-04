
#include <iostream>
#include <sstream>
#include <google/protobuf/message.h>
#include "channel.h"
#include "rpc_meta.pb.h"

Channel::Channel(std::string ip, int port): ip_(ip), port_(port)  {
	Init();
}

int Channel::Init() {
	io_ = std::make_shared<boost::asio::io_service>();
	socket_ = std::make_shared<boost::asio::ip::tcp::socket>(*io_);

	boost::asio::ip::tcp::endpoint ep(
			boost::asio::ip::address::from_string(ip_), port_);
	try {
		socket_->connect(ep);
	} catch (boost::system::system_error se) {
		std::cout << "connect fail. error code: " << se.code() << std::endl;
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
	std::string meta_str;
	meta.SerializeToString(&meta_str);

	int meta_size = meta_str.size();
	std::string serialized_str;
	serialized_str.insert(0, std::string((const char *)&meta_size, sizeof(int)));
	serialized_str += meta_str;
	serialized_str += data_str;


	std::cout << "----------------------" << std::endl;
	std::cout << "send info service" << meta.service_id() << std::endl;
	std::cout << "send info method" << meta.method_id() << std::endl;
	std::cout << "send info data size" << meta.data_size() << std::endl;
	std::cout << "send info meta size" << meta_str.size() << std::endl;
//		std::cout << "recev info data" << << std::endl;

	socket_->send(boost::asio::buffer(serialized_str));

	char resp_data_size[sizeof(int)];
	socket_->receive(boost::asio::buffer(resp_data_size));
	int resp_data_len = *(int *)resp_data_size;
	std::vector<char> resp_buf(resp_data_len, 0);
	socket_->receive(boost::asio::buffer(resp_buf));
	response->ParseFromString(std::string(&resp_buf[0], resp_buf.size()));
	return ;
}
