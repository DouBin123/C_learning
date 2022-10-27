# include <iostream>
const  int Arsize = 10;//不可修改全局变量
void strcount(const char* str);
int main4()
{


	using namespace std;
	char input[Arsize];
	char next;

	cout << "Enter a line:\n";
	cin.get(input, Arsize);//读取字符（包含空白符），Arsize-1个.可以接受空格字符，遇到Enter结束输入，按照长度(Arsize)读取字符, 会丢弃最后的Enter字符
	while (cin)//get(char*,int)读取空行将导致cin为false
	{
		cin.get(next);//读取next,检查输入是否结束
		while (next != '\n')//input的输入停止有两种情况，一种是ENTER，另一种是字符长度为Arsize-1
			//如果是第一种，说明输入结束，读取回车为next，第二种说明输入过长，将剩下一个存储在next
			cin.get(next);
		strcount(input);
		cout << "Enter next line (empty line quit): \n";
		cin.get(input, Arsize);
	}
	cout << "Bye\n";


	system("pause");
	return 0;

}
void strcount(const char * str)
{
	using namespace std;
	static int  total = 0;//静态局部变量
	int count = 0;//局部变量，自由存储持续性

	cout << "\"" << str << "\"contains ";//转义字符
	while (*str++)
	{
		count++;
	}
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";

}