#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>
#include <boost/asio.hpp>
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>

class Server {
	public:
		Server();
		virtual ~Server();

		int Start(std::string ip, int port);

		int Close();

		int AddService(google::protobuf::Service *service, bool ownership);

		//arg is server pointer
		int OnNewConnection();

		//arg is socket fd waiting for read
		static void OnNewMessage(const int socket);

		static void OnCallbackDone(::google::protobuf::Message* response,
				const int fd);

	private:
		struct ServiceInfo {
			::google::protobuf::Service *service;
			std::map<std::string, const ::google::protobuf::MethodDescriptor *> 
				mdescriptor;
		};
		static std::map<std::string, ServiceInfo> services_;

		//epoll fd
		int epfd_;
		//listen fd
		int listen_fd_;
};



#endif //__SERVER_H__
