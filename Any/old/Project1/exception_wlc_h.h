#pragma once
#include <exception>
namespace wlc
{
	class exception_wlc_h : public std::exception
	{
	public:
		exception_wlc_h() {}

		virtual ~exception_wlc_h() {}

		virtual const char* toCString() = 0;
	};
}