#include <time.h>
#include <string>
#include <fstream>
#include <thread>
#include "echo.pb.h"

#include "channel.h"
#include "controller.h"

const static int MAX_TIMES_PER_THREAD = 10;
const static int THREAD_NUM = 10;

int go(int thread_index, int times) {
	echo::EchoRequest req;

	int sum = 0;
	for (size_t i = 0; i < 2; ++i) {
		int r = rand() % 20743;
		req.add_data(r);
		sum += r;
	}

	echo::EchoResponse resp;

	Channel channel;
	if (channel.Init("127.0.0.1", 12321) < 0) {
		std::cout << "channel init failed." << std::endl;
		return -1;
	}
	echo::EchoService_Stub stub(&channel);

	Controller cntl;
	uint64_t log_id = ((uint64_t)thread_index << 40) | times;
	cntl.SetLogId(log_id);

	stub.Get(&cntl, &req, &resp, nullptr);

	if (cntl.Failed()) {
		std::cout << "------------call" 
			<< ((uint64_t)cntl.GetLogId() >> 40) << "." << (cntl.GetLogId() & 0x0000ffff)
			<< " fail." << std::endl 
			<< cntl.ErrorText() << std::endl;
		return -1;
	} else {
		std::cout << "------------call" 
			<< ((uint64_t)cntl.GetLogId() >> 40) << "." << (cntl.GetLogId() & 0x0000ffff)
			<< " success." << std::endl
			<< " svr index: " << resp.index() 
			<< " element size: " << resp.sorted_data_size()
			<< (sum != resp.sum() ? "sum error" : "")  
			<< " sum: " << sum << " " << resp.sum() << std::endl;
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
	srand((unsigned int)time(NULL));
	std::vector<std::thread> threads(THREAD_NUM);
	for (int i = 0; i < THREAD_NUM; ++i) {
		threads[i] = std::thread(thread_run, i);
	}

	for (auto &th : threads) {
		th.join();
	}

	return 0;
}
