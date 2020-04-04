#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>

#include <google/protobuf/service.h>

class Controller : public google::protobuf::RpcController {
	public:
		Controller() { Reset(); }
		virtual ~Controller() {}

		virtual void Reset() { 
			is_failed_ = false;
			err_info_ = "";
		}

		virtual bool Failed() const { return is_failed_; }
		virtual void SetFailed(const std::string &reason) { err_info_ = reason; }
		virtual std::string ErrorText() const { return err_info_; }
		virtual void StartCancel() {  }
		virtual bool IsCanceled() const  { return false; }
		virtual void NotifyOnCancel(google::protobuf::Closure *) {  }


	private:
		bool is_failed_;
		std::string err_info_;
};
#endif //__CONTROLLER_H__
