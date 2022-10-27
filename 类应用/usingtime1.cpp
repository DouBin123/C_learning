# include<iostream>
#include"Mytime0.h"
int main1()
{
	using std::cout;
	using std::endl;

	//创建4个对象
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time= "<<planning;
	
	cout << endl;

	cout << "fixing time = "<<fixing;
	
	cout << endl;

	total = coding+fixing;//将两个对象相“+”（operator+）
	cout << "coding+fixing = "<<total;

	cout << endl;

	Time morefixing(3, 28);
	cout << "more fixing time = "<<morefixing;
	
	total = morefixing.operator+(total);
	cout << "morefixing.oerator+(total) = "<<total;
	
	cout<<endl;

	Time weeding;
	Time waxing;
	weeding = total - fixing;
	cout << " total-fixing = "<<weeding;

	cout << endl;
	double d =1.6;
	waxing = coding*d;//运算符左侧操作数应该为对象
	cout << "1.6*coding = " << d*coding;//根据运算符两边类型确定是哪一个友元函数
	cout << "coding = "<<coding;
	
	cout << endl;
	cout << "total*1.6 = "<<waxing;
	
	cout << endl;

	system("pause");
	return 0;

}