#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include <memory>
#include <google/protobuf/service.h>
#include <boost/asio.hpp>


class Channel : public ::google::protobuf::RpcChannel {
	public:
		Channel();

		virtual ~Channel();

		int Init(std::string ip, int port);

		int Close();
	private:


		void CallMethod(const ::google::protobuf::MethodDescriptor *method,
				::google::protobuf::RpcController *controller,
				const ::google::protobuf::Message *request,
				::google::protobuf::Message *response,
				::google::protobuf::Closure *done); 

		std::string ip_;
		int port_;

		int fd_;
};

#endif //__CHANNEL_H__
