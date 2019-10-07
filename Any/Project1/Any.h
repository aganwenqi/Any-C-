#pragma once
#include "AnyFather.h"

namespace wlc
{
	class Any:public AnyFather
	{
	public:

		Any() :m_data(nullptr)
		{
		}
		template<class Ts>
		inline Any(Ts & data = nullptr) : m_data(nullptr)
		{
			m_data.reset(new AnyData<Ts>(data));
		}
		template<class Ts>
		inline Any(Ts && data) : m_data(nullptr)
		{
			m_data.reset(new AnyData<Ts>(data));
		}

		template<class Ts>
		inline Any(Ts * data = nullptr)
		{
			m_data.reset(new AnyData<Ts>(*data));
		}
		template<class Ts>
		 Ts & get()
		{	
			 if (m_data.get() == nullptr)
				return *(Ts*)nullptr;
			return  strcmp(typeid(Ts).name(), m_data->getName()) ? *(Ts*)nullptr : *(Ts*)getDate();
		}
		 template<class Ts>
		 operator Ts()
		 {
			 if (m_data.get() == nullptr)
				 return *(Ts*)nullptr;

			 //if( strcmp( typeid(Ts).name(), m_data->getName() ) )
				// return (Ts)nullptr;
			 return *(Ts*)getDate();
		 }

		 abstractData & GetDate()
		 {
			 return * m_data;
		 }
		 void setDead(bool quit)
		 {
			 m_data->setDead(quit);
		 }
	protected:
		inline void * getDate()
		{
			return m_data->getData();
		}
	private:
		
		std::unique_ptr<abstractData> m_data;
	};
}
