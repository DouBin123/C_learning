# include <iostream>
using namespace std;
//交换两个变量的值意味着值传递将不可以
#pragma region not_fun
void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);//不可行
double cube(double a);
double refcube(double &ra);//按引用传递会改变实参的值
#pragma endregion
//当引用的对象是const而且类型不正确或不是左值时，会生成临时变量
/*
应尽可能使用const引用
1、使用const可以避免无意中修改数据的编程错误
2、使用const 使函数能够处理const和非const实参，否则将只接受非const数据
3、使用const引用使函数能够正确生成并使用临时变量
*/
//C++11新增了右值引用
double &&reff = sqrt(36.0);
int main2()
{
	//与*运算符一样，在定义或声明变量时，&表示引用变量，表示两个变量共用同一地址和值
#pragma region MyRegion
int rats = 101;
	int &rodents = rats;
	cout << "rats= " << rats << endl;
	cout << ",rodents= " << rodents << endl;
	rodents++;
	cout << "rats= " << rats << endl;
	cout << ",rodents= " << rodents << endl;
	cout << "address rats= " << &rats << endl;
	cout << ",address rodents= " << &rodents << endl;
	int bunnies = 50;
	rodents = bunnies;//引用与原变量的值变了，但地址未变
	cout << "bunnies= " << bunnies << endl;
	cout << "rats= " << rats << endl;
	cout << ",rodents= " << rodents << endl;
	cout << "address bunnies= " << &bunnies << endl;
	cout << "address rats= " << &rats << endl;
	cout << "address rodents= " << &rodents << endl;
	
#pragma endregion
#pragma region swap

	int wallet1 = 300;
	int wallet2 = 320;
	cout << "wallet1=$ "<<wallet1;
	cout << "wallet2=$ " << wallet2<<endl;
	cout << "Using references to swap contents:\n";
	swapr(wallet1, wallet2);
	cout << "wallet1=$ " << wallet1;
	cout << "wallet2=$ " << wallet2 << endl;
	cout << "Using references to swap contents agin:\n";
	swapp(&wallet1, &wallet2);
	cout << "wallet1=$ " << wallet1;
	cout << "wallet2=$ " << wallet2 << endl;
	cout << "Trying to use passing by value:\n";
	swapv(wallet1, wallet2);
	cout << "wallet1=$ " << wallet1;
	cout << "wallet2=$ " << wallet2 << endl;

#pragma endregion
#pragma region cube
	double x = 3.0;
	cout << cube(x);
	cout << "= cube of " << x << endl;
	cout << refcube(x);
	cout << "= cube of " << x << endl;

#pragma endregion
	system("pause");
	return 0;

}
void swapr(int &a, int &b)//按引用传递
{
	int temp=a;
	a = b;
	b = temp;
}
void swapp(int *p, int *q)//按地址传递
{
	int temp = *p;
	*p = *q;
	*q = temp;

}
void swapv(int a, int b)//按值传递，相当于复制了原实参的值
{
	int temp = a;
	a = b;
	b = temp;

}
double cube(double a)
{
	a *= a*a;
	return a;
}
double refcube(double &ra)
{
	ra *= ra*ra;
	return ra;
}