# include <iostream>
using namespace std;
unsigned long left(unsigned long num, unsigned ct);
char *left(const char *str, int n = 1);
//函数多态（重载）允许可以使用多个同名函数，完成相同功能，使用不同参数
//返回类型可以不同，但特征标（参数）必须不同
//非const 可以赋给const，但反之不行
//同一项目中不能定义相同的函数
/*
左值指既能够出现在等号左边，也能出现在等号右边的变量；右值则是只能出现在等号右边的变量
左值是可寻址的变量，有持久性；
右值一般是不可寻址的常量，或在表达式求值过程中创建的无名临时对象，短暂性的。

int x = 6; // x是左值，6是右值
int &y = x; // 左值引用，y引用x

int &z1 = x * 6; // 错误，x*6是一个右值
const int &z2 =  x * 6; // 正确，可以将一个const引用绑定到一个右值

int &&z3 = x * 6; // 正确，右值引用
int &&z4 = x; // 错误，x是一个左值
*/
int main7()
{
	char *trip = "Hawaii";
	unsigned long n = 12345678;
	int i;
	char *temp;
	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}


	system("pause");
	return 0;
}
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;//统计数的位数
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;//由低位向高位求解
		return num;
	}
	else
		return num;//要求截取的位数大于给定的数字位数时，输出原数字

}
char * left(const char  *str, int n)//截取字符串
{
	if (n < 0)
		n = 0;
	char*p = new char[n + 1];
		int i;
		for (i = 0; i < n&&str[i]; i++)
			p[i] = str[i];
		while (i <= n)
		{
			p[i++] = '\0';
		}
		return p;

}