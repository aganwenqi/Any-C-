#pragma once
#include <iostream>
#include "exception_wlc_h.h"
namespace wlc
{
	class exception_wlc : public exception_wlc_h
	{
	public:
		exception_wlc(std::string data);
		virtual ~exception_wlc()override;

	    virtual const char* toCString()override;
	private:
		std::string data;
	};
}