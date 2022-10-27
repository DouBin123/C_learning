# include <iostream>
using namespace std;
//*********C++的返回值不能为数组，但可以是结构和对象，因此可以将数组作为结构、对象的组成来返回
//不指定参数列表时应该用...
//实参：argument,形参：parameter
/*
处理函数常用的编写方式：
函数不修改数组：void fun(const double x[]);//a[]=*a，指出a是指针
函数可以修改数组：void fun(double *x);
指定数组区间：void fun(int* begin,int*end);//调用时给定数组区间地址
const int *pt=&a; int *pt=&a;//可以通过pt和p访问a的值，但不能通过p修改a，而且p的值可修改
int  *const pm,则pm的值也无法修改
禁止将const赋给非const指针，除非强制转换
*/
//************************函数与二维数组*****************
/*
arr=&arr[0],&arr=整个数组的首地址，arr[k]=*(arr+k),k<n;
int data[3][4]=｛｛1,2,3,4｝，｛4,5,6,7｝，｛7,8,9,0｝｝;
int (*data)[4]=int data[][4];//定义一个数组指针，data指向int [4]的数组
//int *data[4];//定义一个指针数组，4个元素为指向int 的指针
data指向数组（它的元素是4个int组成的数组）的第一个元素，因此data[r]指向编号为r的元素，该元素为一个数组，故data[r]也是由4个int元素组成的数组的名称
data[r][c]是由4个int组成的数组的第一个元素：data[r][c]=*（*（data+r）+c）：*（data+r）=data[r]
data[1]=*(data+1)=｛4,5,6,7｝=arr[4]
data[1][3]=*(data[1]+3)=*(arr+3)=7
*/
unsigned int c_in_str(const char *str, char ch);//函数声明
int main18()
{
	char mmm[15] = "minimum";
	char *wail = "ululate";//wail point to string
	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << ms << " m characters in " << mmm << endl;
	cout << us << " u characters in " << wail << endl;


	system("pause");
	return 0;
}
unsigned int c_in_str(const char* str, char ch)
{
	unsigned int count = 0;

	while (*str)//quit when *str is '\0'
	{
		if (*str == ch)
			count++;
		str++;//move pointer to next char
	}
	return count;
}