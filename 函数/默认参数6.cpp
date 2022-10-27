# include <iostream>
using namespace std;
const int ArSize = 80;
char *left1(const char * str, int n = 1);//只能从右向左设置默认参数，在调用函数时可以省略该参数
int main6()
{
	char sample[ArSize];
	cout << "Enter a string: \n";
	cin.get(sample, ArSize);
	char *ps = left1(sample, 4);//函数返回值为指针，类型匹配
	cout << ps << endl;
	delete[] ps;//释放内存,因为在函数调用时使用了new char[]
	ps = left1(sample);
	cout << ps << endl;
	delete[] ps;


	system("pause");
	return 0;
}
char *left1(const char *str, int n)
{
	if (n < 0)
	{
		n = 0;
	}
	char *p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++)
	{
		p[i] = str[i];
	}//继续保持i,读取完n个非空字符之后在后面赋‘\0’
	while (i <= n)
			p[i++] = '\0';
	return p;

}