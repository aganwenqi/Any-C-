#pragma once

#include <iostream>
#include <map>
#include <memory>
#include "exception_wlc.h"
	/*
	*			        Universal template library
	*  Explain : This container can hold any type of data at the same time
	*  Matters needing attention : This library only supports c++14 or higher
	*
	*           Making time : 2017.10.11 and version 1.0
	*
	*                                   The writer is Gan Wenqi
	*
	*/
		
namespace wlc
{
	class AnyFather
	{
	public:

	protected:
		/* data class */
		class abstractData
		{
		public:
			abstractData() {};
			virtual void* getData() = 0;
			virtual const char* getName() = 0;
			virtual ~abstractData() {}
		};
		template<class _T>
		class AnyData : public abstractData
		{
		public:
			AnyData(_T a) :m_data(a) {}
			AnyData() {}
			~AnyData()
			{
				cout << "unique is delete!!" << endl;
				//m_data = NULL;
			}

		    auto getData()
			{
				return &m_data; 
			}
			virtual const char* getName()override
			{
				return typeid(m_data).name();
			}
		private:
			_T m_data;
		};

		/* return void point data */
		template<class Ts>
		auto att(const Ts &key);

	};
	
}
