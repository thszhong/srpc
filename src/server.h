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

		int AddService(google::protobuf::Service *service, bool ownership);

		int ProcRpcMsg(const std::string &service_id,
				const std::string &method_id,
				const std::string &serialized_data,
				const std::shared_ptr<boost::asio::ip::tcp::socket> socket);

		void OnCallbackDone(::google::protobuf::Message* response,
				const std::shared_ptr<boost::asio::ip::tcp::socket> socket);

	private:
		std::string ip_;
		int port_;

		struct ServiceInfo {
			::google::protobuf::Service *service;
			std::map<std::string, const ::google::protobuf::MethodDescriptor *> 
				mdescriptor;
		};
		std::map<std::string, ServiceInfo> services_;
};



#endif //__SERVER_H__
