# include <iostream>
# include "String1.h"
using  std::cout;

void callme1(String1 &);//pass by reference
void callme2(String1);

int main1()
{
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		String1 headingline1("Celery Stalks at Midnight");
		String1 headingline2("Lettuce Prey");
		String1 sports("Spinach Leaves Bowl for Dollars");

		cout << "headline1: " << headingline1 << endl;
		cout << "headline2: " << headingline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headingline1);
		cout << "headline1: " << headingline1 << endl;
		callme2(headingline2);//按值引用对象，生成临时对象，调用复制构造函数，导致析构函数被调用，源字符串无法识别
		cout << "headline2: " << headingline2 << endl;
		cout << "Initialize one object to another:\n";
		
		String1 sailor = sports;//使用复制构造函数
		//String1(const SringBad &);使用一个对象来初始化另一个对象时，自动生成
		cout << "sailor: " << sailor << endl;
		cout << "Assign one object to another:\n";
		String1 knot;
		knot = headingline1;//使用赋值运算符，复制的是地址不是字符串，原对象调用析构函数时，地址无效
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	}
	system("pause");
	return 0;
}

void callme1(String1 & rsb)
{
	cout << "String passed by reference:\n";
	cout << "   \"" << rsb << "\"\n";

}
void callme2(String1 sb)
{
	cout << "String passed by value:\n";
	cout << "  \"" << sb << "\"\n";

}