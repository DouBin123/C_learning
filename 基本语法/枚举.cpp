# include <iostream>
using namespace std;
int main4()
{
	enum spectrum{red,orange,yellow};//对应0-2
	spectrum brand;//实例化变量
	brand = red;//只有赋值运算，不能算数运算
	enum bigstep{ first,second=100,third};//0,100,101
	enum { zero, null, one, num = 1};//0,0,1,1
	bigstep a = bigstep(50);//在范围内，合法
	cout << a << endl;
	cout << red << endl;
	cout << third << endl;




	system("pause");
	return 0;
}