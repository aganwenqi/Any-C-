#include "exception_wlc.h"

namespace wlc
{
	using namespace std;
	exception_wlc::exception_wlc(string data)
	{
		this->data = data;
	}
	exception_wlc::~exception_wlc()
	{

	}
	const char * exception_wlc::toCString()
	{
		return data.c_str();
	}
   
}