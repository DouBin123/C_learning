# include <iostream>
# include <fstream>
using namespace std;
int main16()
{
	char automobile[50];
	int year;
	double a_price;
	double b_price;
	ofstream outFile;//创建一个输出对象
	outFile.open("carinfi.txt");//将对象与文件关联,并建立一个文本文件；

	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	b_price = 0.913*a_price;
	//***************************输出流控制******************
	/*
boolalpha    可以使用单词”true”和”false”进行输入/输出的布尔值.
oct    用八进制格式显示数值.
dec    用十进制格式显示数值.
hex    用十六进制格式显示数值.
left    输出调整为左对齐.
right    输出调整为右对齐.
scientific    用科学记数法显示浮点数.
fixed    用正常的记数方法显示浮点数(与科学计数法相对应).
showbase    输出时显示所有数值的基数.
showpoint    显示小数点和额外的零，即使不需要.
showpos    在非负数值前面显示”＋（正号）”.
skipws    当从一个流进行读取时，跳过空白字符(spaces, tabs, newlines).
unitbuf    在每次插入以后，清空缓冲区.
internal    将填充字符回到符号和数值之间.
uppercase    以大写的形式显示科学记数法中的”e”和十六进制格式的”x”.
		
	*/
	
	//cout << fixed<<precision(2)
	cout << fixed;//浮点数的输出以小数形式
	cout.precision(2);//设置小数精度为后两位
	cout.setf(ios_base::showpoint);//显示小数点和额外的0
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << b_price << endl;

//创建的输出对象可以使用cout的任何方法
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile<< "Now asking $" << b_price << endl;

	outFile.close();//关闭文本文件





	system("pause");
	return 0;
}