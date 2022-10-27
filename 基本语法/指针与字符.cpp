# include <iostream>
# include <cstring>

int main6()
{

	using namespace std;
	char animal[20] = "bear";
	const char * bird = "wren";//"wren"=s[],bird=s
	char * ps;
	cout << animal << " and ";
	cout << bird << "\n";
	//cout << ps << "\n";//这里由于ps未初始化会导致编译错误
	cout << "Enter a kind of animal: ";
	cin >> animal;
	ps = animal;
	cout << ps << "!\n";//直接输出fox,与使用animal一样，打印字符数组名等于打印字符串
	cout << "Before uisng strcpy(): \n";
	cout << animal << " at " << (int*)animal << endl;//强制类型转换
	cout << ps << " at " << (int*)ps << endl;
	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);//接收的参数是字符数组的地址
	cout << "After using strcpy(): \n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;
	delete [] ps;


	system("pause");
	return 0;
}
//char a[]={'a','a','a','\0'};
//str___(const char *,const char *,int   a,……)：包含在<cstring>中，形参均为字符指针
//std::string l="asb";//自动添加‘\0’