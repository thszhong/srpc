#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include <memory>
#include <google/protobuf/service.h>
#include <boost/asio.hpp>


class Channel : public ::google::protobuf::RpcChannel {
	public:
		Channel(std::string ip, int port);

		virtual ~Channel() {}

	private:

		int Init();

		void CallMethod(const ::google::protobuf::MethodDescriptor *method,
				::google::protobuf::RpcController *controller,
				const ::google::protobuf::Message *request,
				::google::protobuf::Message *response,
				::google::protobuf::Closure *done); 

		std::string ip_;
		int port_;
		std::shared_ptr<boost::asio::io_service> io_;
		std::shared_ptr<boost::asio::ip::tcp::socket> socket_;
};

#endif //__CHANNEL_H__
