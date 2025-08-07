//hjqstl2 stl2base.h version:2.0.0-alpha.2+build.20250705
#ifndef _HJQ_STL2BASE
#define _HJQ_STL2BASE
#define _HJQ_STL2BASE_MAJOR 2
#define _HJQ_STL2BASE_MINOR 0
#define _HJQ_STL2BASE_PATCH 0
#define _HJQ_STL2BASE_FULLVERSION "2.0.0-alpha.2+build.20250705"
#define _HJQ_STL2BASE_VERSION "2.0.0"
#include<stdio.h>
#include<stdlib.h>
namespace hjq {
	int Output(const char* str) {
		return printf("%s",str);
	}
	//Exception
	class Exception {
		private:
			const char* except;
			int cod;
		public:
			Exception(const char* exce="Exception",int c=0xc0000005) {
				except=exce;
				cod=c;
			}
			const char* what() const throw() {
				return except;
			}
			const int code() const throw() {
				return cod;
			}
	};
	static void(*global_callback)(const Exception&)=nullptr;
	void Set_Global_Exception_Callback(void(*callback)(const Exception&)=nullptr) {
		global_callback=callback;
	}
	bool Has_Global_Exception_Callback() {
		return (global_callback!=nullptr);
	}
	void Throw(const Exception &e,void(*callback)(const Exception&)=nullptr) {
		if(callback) {
			callback(e);
			return;
		} else if(global_callback) {
			global_callback(e);
			return;
		}
		fprintf(stderr,"Exception:%s\nThe program will be exited with code %d.",e.what(),e.code());
		exit(e.code());
	}
}
#endif
