#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include "Any.h"
#include <list>
#include <string>
#include <any>
using namespace std;
using namespace wlc;
void TestSpeed_any();//C++17 any，速度对比
void TestSpeed_Any();//自制 any，速度对比
void TestSpeed();//指定类型，速度对比

void TestSetObject();//设置对象与内存对比
void TestRecycle();//垃圾回收对比

class test2
{
public:
	test2(string a = "") :_str(a), hide(false){ }
	void print()
	{
		cout << "值:" << _str.c_str() << std::endl;
	}
	~test2() 
	{
		if(hide)
			cout << "删除:"<< _str << endl;
	}
	void set(int a) { _str = a; }
	void setHide(bool val) { hide = val; }
private:
	bool hide;
	string _str;
};

void main()
{
	//TestSpeed_any();
	//TestSpeed_Any();
	//TestSpeed();
	//TestSetObject();
	TestRecycle();
	cin.get();
}

void TestSpeed_any()//C++
{
	vector<any> ve;
	test2 *ff = new test2("ff");
	for (int i = 0; i < 1000;i++)
	{
		ve.push_back(*ff);
	}
	
	cout << "打印：" << endl;
	for (int i = 0; i < 100;i++)
		 ve.at(i)._Cast<test2>()->print();

	cout << "ss" << endl;
}
void TestSpeed_Any()//作者
{
	vector<Any> ve;
	test2 *ff = new test2("ff");
	for (int i = 0; i < 1000;i++)
	{
		ve.push_back(ff);
	}

	cout << "打印：" << endl;
	for (int i = 0; i < 1000;i++)
		ve.at(i).get<test2>().print();
	cout << "ss" << endl;
}
void TestSpeed()//指定类型
{
	vector<test2> ve;
	for (int i = 0; i < 1000;i++)
	{
		ve.push_back(test2("ff"));
	}
	cout << "打印：" << endl;
	for (int i = 0; i < 1000;i++)
		ve.at(i).print();
	cout << "ss" << endl;
}
void TestSetObject()//设置对象对比
{
	any anyCjj = 5;
	Any anySelf = 5;
	/*
	cout << "anyCjj值：" << *anyCjj._Cast<int>()<<endl;
	cout << "anySelf值：" << anySelf.get<int>()<<endl;

	
	anyCjj = test2("我是any");
	anySelf = new test2("我是any");

	cout << "赋值非系统变量："<< endl;
	cout <<"anyCjj值：" ;
	anyCjj._Cast<test2>()->print();
	cout <<  "anySelf值：";
	anySelf.get<test2>().print();*/

	anyCjj = 5;
	test2 ff=test2("我是any");
	anySelf = ff;
	//anyCjj = anySelf;
	cout << "交换后的：" << endl;
	cout << "anySelf值：" << *anySelf.get<any>()._Cast<int>() << endl;
	cout << "anySelf值：" << anyCjj._Cast<Any>()->get<int>() << endl;
	return;
	cout << "anyCjj占用字节：" << sizeof(anyCjj) << endl;
	cout << "anySelf占用字节：" << sizeof(anySelf) << endl;
}
void TestRecycle()//垃圾回收对比
{
	string * t1 = new string("anyCjj,请看着我，我在析构函数里会打印");
	test2 * t2 = new test2("anySelf,请看着我，我在析构函数里会打印");
	t2->setHide(true);//打开析构函数里打印“删除”

	any anyCjj = *t1;
	Any anySelf = *t2;
	anySelf.setDead(true);//打开可以GC被保存的堆中数据，默认是只会GC自己
}