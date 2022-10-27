/*
使用引用参数的几种情况：
1、可以修改调用参数中的数据对象
2、通过传递引用而不是数据对象，可以提高程序的运行速度（较大的结构和类对象）
*/
//*****************值传递与引用传递和指针传递********
/*
1、如果数据对象很小，如内置数据类型或小型结构，则按值传递
2、数据对象是数组，使用const指针
3、数据对象是较大的结构，使用const 指针或 const 引用，可以节省复制所需要的时间和空间
4、数据对象是类对象，使用const引用
*/
//*******************修改调用函数数据的函数*********
/*
1、数据对象是内置数据类型，使用指针
2、数据对象是数组，只能使用指针
3、数据对象是结构，则使用引用或指针
4、数据对象是类对象，使用引用
*/

# include <iostream>
# include <fstream>
# include<cstdlib>
using namespace std;
void file_it(ostream &os, double fo, const double fe[], int n);
const int LIMIT = 5;
//ofstream是派生类，ostream是基类，因此ofstream的对象（fout）或引用对象(os)可以使用基类的方法
//派生类继承了基类的方法，基类引用可以指向派生类对象
int main5()
{
	ofstream fout;
	const char *fn = "ep_data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open" << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}	
	double objective;
	cout << "Enter the focal length of your""telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal length ,in mm,of " << LIMIT << "eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepieces # " << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);//写入文件
	file_it(cout, objective, eps, LIMIT);//显示
	cout << "Done\n";
	system("pause");
	return 0;


}
//参数os（其类型是 ostream &）即 既可以指向ostream对象（cout）,又可以指向ofstream对象（fout）
void file_it(ostream &os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;//存储使用函数之前的信息的数据类型,没有的话变成科学计数法表示
	initial = os.setf(ios_base::fixed);//设置输出流为定点输出格式
	os.precision(0);
	os << "Focal length of objective: " << fo << "mm\n";//1800无小数输出
	os.setf(ios::showpoint);
	os.precision(1);//一位小数
	//os.width(12);
	os << "f.1. eyepieces";
	//os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);//还原数据类型
}
/*
ios_base::flags，读取/设置流的格式。
ios_base::setf，设置流的格式，与原有格式合并。
ios_base::unsetf，根据参数mask，清除流的格式的某些位（bit）。
ios_base::precision，读取 / 设置显示浮点数时的精度。
ios_base::width，读取 / 设定流的输出数据的显示宽度。
*/