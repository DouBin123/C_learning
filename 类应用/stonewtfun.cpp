# include <iostream>
#include"stonewt.h"

Stonewt::Stonewt(double lbs)//只接受一个参数，可以做转换函数,隐式，前面加explicit可以关闭这种特性
//接受double a=12.0;Stone stone=stone1+a;(定义了operator+),判断+的运算符前面为对象，则后面的值隐式转换为对象了
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn*Lbs_per_stn + lbs;

}
Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt()
{
}
void Stonewt::show_stn()const
{
	std::cout << stone << " stone, " << pds_left << " pounds\n";

}
void Stonewt::show_lbs()const
{
	std::cout << pounds << " pounds\n";
}
//conversion function overloading
Stonewt::operator int()const
{
	return int(pounds + 0.5);
}
Stonewt::operator double()const
{
	return pounds;

}