#include <string>
#include <fstream>
#include <unistd.h>
#include <atomic>

#include "server.h"
#include "echo.pb.h"

std::atomic<int> g_index(1);

class EchoServiceImpl : public ::echo::EchoService {
	public:
		EchoServiceImpl() {
		}

		void Get(::google::protobuf::RpcController * controller, 
				const ::echo::EchoRequest *request,
				::echo::EchoResponse *response,
				::google::protobuf::Closure *done) {
			while (rand() & 0x0001) {
				usleep(1000);
			}
			response->set_index(g_index);
			g_index++;

			std::vector<int> v;
			for (int i = 0; i < request->data_size(); ++i) {
				v.push_back(request->data(i));
			}
			std::sort(v.begin(), v.end());
			int s = 0;
			for (auto d : v) {
				response->add_sorted_data(d);
				s += d;
			}
			response->set_sum(s);

			done->Run();
		}
	private:
};


int main() {
	srand((unsigned int)time(NULL));
	::echo::EchoService *es_ptr = new EchoServiceImpl();
	Server server;
	if (0 != server.AddService(es_ptr, false)) {
		std::cout << "register service failed" << std::endl;
		return -1;
	}
	std::cout << "start" << std::endl;

	if (0 != server.Start("127.0.0.1", 12321)) {
		std::cout << "Start server failed. " << std::endl;
	}

	delete es_ptr;

	return 0;
}
