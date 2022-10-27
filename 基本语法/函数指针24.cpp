# include <iostream>
double betsy(int);//函数声明中可以省略标识符，但在定义函数时必须说明标识符
double pam(int);
void estimate(int lines, double(*pf)(int));
using namespace std;
int main24()
{
	//函数名即函数地址，函数名（）为返回值。
	/*
	int * pt (int)//定义一个函数，其返回值为int*类型
	int （*p）(int)//定义一个函数指针p，指向int fun(int a);
	*/
	int code;
	cout << "How many lines of code do you need ? ";
	cin >> code;
	cout << "Here's Betsy's estimate:\n";
	estimate(code, betsy);
	cout << "Here's Pam's estimate:\n";
	estimate(code, pam);
//调用函数时可以用*函数名或直接使用函数名
	system("pause");
	return 0;
}
void estimate(int lines,double (*pf)(int))
{
	cout << lines << "lines will take ";
	cout << (*pf)(lines) << "hours\n";//调用函数

}
double betsy(int lns)
{
	return 0.05*lns;
}
double pam(int lns)
{
	return 0.03*lns + 0.0004*lns*lns;

}