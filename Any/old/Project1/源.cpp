#include "AnyMap.h"
#include <algorithm>
#include <functional>
#include "exception_wlc.h"
#include <map>
#include <vector>
#include "Any.h"
#include "Any1.h"
#include <list>
#include <string>
#include <any>
using namespace std;
using namespace wlc;
void testone();
void testtwo();
void testtwo2();
void testtwo3();
class ceshi
{
public:
	ceshi(int a = 3) :b(a) {  }
	void print()
	{
		std::cout << "ceshi:" << b << std::endl;
	}
	~ceshi() 
	{
		//cout << "删除ceshi" << endl;
	}
	void set(int a) { b = a; }
	int b;
	int ss;
	int f, s, fw, a, g;
};

class test2
{
public:
	test2(string a = "") :b(a) { }
	void print()
	{
		cout << "test2:";
		cout << b.c_str() << std::endl;
	}
	~test2() 
	{
		//cout << "删除" << endl;
	}
	void set(int a) { b = a; }
	string b;
};

void main()
{
	int i;
	//testone();
	//testtwo();
	testtwo2();
	//testtwo3();
	cin >>i;
	//return 0;
}
void testone()
{
	
	//any_cast<ceshi&>(s).print();
	/*自定义键值万用类*/
	AnyMap<int> anymap;
	std::vector<string> ver;
	ver.push_back("ver one data");
	ver.push_back("ver two data");
	try {
		/* 插入各种数据 */
		anymap.insert(1, ceshi(520));
		anymap.insert(3, 30);
		anymap.insert(4, string("string"));
		anymap.insert(10, &ver);
		anymap.insert(20, new test2("new test"));
		anymap.insert(21, test2("test"));
		anymap.insert(2, "dsfsfsf");

		/* 获取数据并进行修改 */
		anymap.at<ceshi>(1)->set(12300);

		anymap[2];
		anymap.at<test2>(20)->print();
		cout << anymap.at<char>(2) << endl;
		cout << anymap.at<std::vector<string>>(10)->at(1).c_str() << endl;

		/*删除数据，不需要手动delete开辟的空间*/
		anymap.eraseAll();
	}
	catch (exception_wlc_h &e)
	{
		cout << "异常出现!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << e.toCString() << endl;
	}
}
void testtwo()
{
	vector<Any> ve;
	for (int i = 0; i < 1000;i++)
	{
		ve.push_back(new test2("德玛西亚"));
	}

	cout << "德玛西亚" << endl;
	for (int i = 0; i < 1000;i++)
		ve.at(i).get<test2>().print();
	cout << "ss" << endl;
}
void testtwo2()
{
	
	any a = test2("德玛西亚");
	a.emplace<test2>().print();
	a._Cast<test2>()->print();
	any b = 3;
	cout<< *b._Cast<int>();
	return;
	vector<any> ve;
	for (int i = 0; i < 1000;i++)
	{
		ve.push_back(new test2("德玛西亚"));
	}
	
	cout << "德玛西亚" << endl;
	for (int i = 0; i < 1000;i++)
		std::any_cast<test2>(ve.at(i));
		//ve.at(i).emplace<test2>().print();
	cout << "ss" << endl;
}
void testtwo3()
{
	vector<test2*> ve;
	for (int i = 0; i < 1000;i++)
	{
		ve.push_back(new test2("德玛西亚"));
	}
	cout << "德玛西亚" << endl;
	for (int i = 0; i < 1000;i++)
		ve.at(i)->print();
	cout << "ss" << endl;
}