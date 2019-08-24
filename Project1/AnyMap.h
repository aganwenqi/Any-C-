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
namespace wlc{
	template<class T>
	class AnyMap
	{
	public:
		/* insert &data */
		template<class Ts>
		void insert(const T &key, Ts *data);

		/* insert data */
		template<class Ts>
		void insert(const T &key, Ts data);

		/* return data */
		//template<class Ts>
		//auto at(const T &key, Ts type);

		/* return data */
		template<class Ts>
		auto at(const T &key);

		/*if exist*/
		const bool iskey(const T &key);

		/*if null*/
		const bool empty();

		/*size*/
		const auto size();

		/*erase*/
		const bool erase(T key);

		/*erase*/
		void eraseAll();

		/*operator[key]*/
		auto operator[](T key);

		/*
		 struct type
		{
			 int int_wlc;
			 float float_wlc;
			 double double_wlc;
			 std::string string_wlc;
			 char char_wlc;
			 char *CString="";
		};
		 type type_wlc;*/
	protected:
		/* data class */
		class abstractData
		{
		public:
			abstractData() {};
			virtual void* getData() = 0;
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

			auto getData() { return &m_data; }
		private:
			_T m_data;
		};

		/* return void point data */
		auto att(const T &key);

	private:
		std::map<T, std::unique_ptr<abstractData>> m_data;
	};
	/*....................................................................*/
	/*if exist*/
	template<class T>
	const bool AnyMap<T>::iskey(const T &key)
	{
		if (m_data.find(key) == m_data.end())
		{
			return false;
		}
		return true;
	}

	/*if null*/
	template<class T>
	const bool AnyMap<T>::empty()
	{
		return m_data.empty();
	}

	/*size*/
	template<class T>
	const auto AnyMap<T>::size()
	{
		return m_data.size();
	}
	/*erase*/
	template<class T>
	const bool AnyMap<T>::erase(T key)
	{
		if (!iskey(key))
			throw exception_wlc("Key value does not exist : " + key);

		return m_data.erase(key) ? true : false;
	}

	/*erase*/
	template<class T>
	void AnyMap<T>::eraseAll()
	{
		m_data.clear();
	}
	template<class T>
	template<class Ts>
	void AnyMap<T>::insert(const T &key, Ts *data)
	{
		if ( iskey(key) )
			throw exception_wlc("Key already exists : "+key);
		m_data.insert(std::make_pair(key, new AnyData<decltype(*data)>(*data)));
	}
	template<class T>
	template<class Ts>
	void AnyMap<T>::insert(const T &key, Ts data)
	{
		if (iskey(key))
			throw exception_wlc("Key already exists : " + key);
		m_data.insert(std::make_pair(key, new AnyData<decltype(data)>(data)));
	}
	
	template<class T>
	auto AnyMap<T>::att(const T &key)
	{
		if ( !iskey(key) )
			throw exception_wlc("Key value does not exist : " + key);
		return m_data.at(key)->getData();
	}
	template<class T>
	template<class Ts>
	auto AnyMap<T>::at(const T &key)
	{
		if (!iskey(key))
			throw exception_wlc("Key value does not exist : " + key);
		return (Ts*)att(key);
	}
	/*operator[key]*/

	template<class T>
	auto AnyMap<T>::operator[](T key)
	{
		if (!iskey(key))
			throw exception_wlc("Key value does not exist : " + key);

		return att(key);
	}
	/* return data 
	template<class T>
	template<class Ts>
	auto AnyMap<T>::at(const T &key, Ts type)
	{
		if (!iskey(key))
			throw exception_wlc("Key value does not exist : " + key);
		return (decltype(type)*)at(key);
	}*/

}