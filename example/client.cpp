#include <string>
#include <fstream>
#include <thread>
#include "echo.pb.h"

#include "channel.h"
#include "controller.h"

const static int MAX_TIMES_PER_THREAD = 10000;
const static int THREAD_NUM = 10;

int go(int thread_index, int times) {
	echo::EchoRequest req;
	req.set_question("coco cola");
	echo::EchoResponse resp;

	Channel channel;
	if (channel.Init("127.0.0.1", 12321) < 0) {
		std::cout << "channel init failed." << std::endl;
		return -1;
	}
	echo::EchoService_Stub stub(&channel);

	Controller cntl;
	stub.Get(&cntl, &req, &resp, nullptr);

	if (cntl.Failed()) {
		std::cout << "thread " << thread_index 
			<< " index " << times 
			<< " fail." << cntl.ErrorText() 
			<< std::endl;
	} else {
		std::cout << "thread: " << thread_index 
			<< " index: " << times 
			<< " resp: " << resp.result()
			<< std::endl;
	}
	return 0;
}
void thread_run(int thread_index) {
	int times = 1;
	while (times <= MAX_TIMES_PER_THREAD) {
		go(thread_index, times);
		++times;
	}
}

int main() {
	std::vector<std::thread> threads(THREAD_NUM);
	for (int i = 0; i < THREAD_NUM; ++i) {
		threads[i] = std::thread(thread_run, i);
	}

	for (auto &th : threads) {
		th.join();
	}

	return 0;
}
