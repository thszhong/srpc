#include <string>
#include <fstream>
#include "echo.pb.h"

#include "channel.h"
#include "controller.h"

int main() {
	echo::EchoRequest req;
	req.set_question("coco cola");
	echo::EchoResponse resp;

	Channel channel("127.0.0.1", 12321);
	echo::EchoService_Stub stub(&channel);

	Controller cntl;
	stub.Get(&cntl, &req, &resp, nullptr);

	if (cntl.Failed()) {
		std::cout << "fail." << cntl.ErrorText() << std::endl;
	} else {
		std::cout << "resp:" << resp.result() << std::endl;
	}
	return 0;
}
