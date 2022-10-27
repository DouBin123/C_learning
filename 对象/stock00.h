#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock
{
private  ://数据隐藏，只能通过公共成员来访问，可以防止直接访问成员
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot(){ total_val = shares*share_val; }
	//在类声明中定义的函数可以直接成为内联函数
public://公共接口的类成员
	Stock();//默认构造函数
	Stock(const std::string &co, long n = 0, double pr = 0.0);//重载构造函数
	~Stock();//构析函数
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show()const;//确保调用对象值不会修改
	const Stock & topval(const Stock &s)  const;//(const Stock &s):显式调用一个对象的引用，对象.topval():隐式调用另一对象（该对象调用了成员函数）
};



#endif