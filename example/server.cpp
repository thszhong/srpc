#include <string>
#include <fstream>

#include "server.h"
#include "echo.pb.h"


class EchoServiceImpl : public ::echo::EchoService {
	public:
		EchoServiceImpl() {
			_index = std::make_shared<int>();
			*_index = 0;
		}

		void Get(::google::protobuf::RpcController * controller, 
				const ::echo::EchoRequest *request,
				::echo::EchoResponse *response,
				::google::protobuf::Closure *done) {
			std::cout << "receive " << request->question() << std::endl;

			response->set_result(*_index);
			*_index = *_index + 1;

			done->Run();
		}
	private:
		std::shared_ptr<int> _index;
};


int main() {

	std::cout << "ready" << std::endl;
	::echo::EchoService *es_ptr = new EchoServiceImpl();
	std::cout << "ready2" << std::endl;
	Server server;
	std::cout << "ready3" << std::endl;
	if (0 != server.AddService(es_ptr, false)) {
		std::cout << "register service failed" << std::endl;
		return -1;
	}
	std::cout << "start" << std::endl;

	if (0 != server.Start("127.0.0.1", 12321)) {
		std::cout << "Start server failed. " << std::endl;
	}

	return 0;
}
