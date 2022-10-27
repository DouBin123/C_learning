# include <iostream>
# include"Mytime0.h"
Time::Time()
{
	hours = minutes = 0;

}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;

}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;

}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;

}
//重载运算符
Time Time::operator+(const Time&t)const//不要返回局部变量和临时对象的引用，因为在程序结束后该对象被删除，引用指向一个不存在的对象
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;

}
Time Time::operator-(const Time&t)const//不要返回局部变量和临时对象的引用，因为在程序结束后该对象被删除，引用指向一个不存在的对象
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;//hours属于调用成员函数的对象
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	
	return diff;

}
Time Time::operator*(double mult)const//不要返回局部变量和临时对象的引用，因为在程序结束后该对象被删除，引用指向一个不存在的对象
{
	Time result;
	long totalminutes = hours*mult * 60 + minutes*mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;

}
std::ostream & operator<<(std::ostream &os, const Time &t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;

}
//第一个参数（左边）为ostream对象，第二个参数（右边）为定义类的对象