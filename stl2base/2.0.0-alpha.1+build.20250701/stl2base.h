//hjqstl2 stl2base.h version:2.0.0-alpha.1+build.20250701
#ifndef _HJQ_STL2BASE
#define _HJQ_STL2BASE
#define _HJQ_STL2BASE_MAJOR 2
#define _HJQ_STL2BASE_MINOR 0
#define _HJQ_STL2BASE_PATCH 0
#define _HJQ_STL2BASE_FULLVERSION "2.0.0-alpha.1+build.20250701"
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
	void Throw(const Exception &e) {
		fprintf(stderr,"Exception:%s\nThe program will be exited with code %d.",e.what(),e.code());
		exit(e.code());
	}
}
#endif
