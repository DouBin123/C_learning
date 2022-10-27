# include <iostream>

int main1()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	int year;
	//cin >> year;//这里结束后有回车符会被getline()采集到，误认为之后的输入是空行
	(cin >> year).get();//不同输入类型的解决之道
	cout << "Enter your name:\n";
	//cin >> name;//解决方案，采用cin.getline(),回车键来确定该行是否结束，会删除换行符
	//cin.get(name,ArSize);
	//cin.get();//get()可以读取下一字符，及时是换行符
	//cin.get(dessert, ArSize);//get(参数)函数会保留换行符，因此在第二个变量未输入时就认为已经换行结束
	cin.get(name, ArSize).get();//cin.get(name, ArSize).get()=cin.get(name,ArSize);cin.get();
	cout << "Enter your favourate dessert:\n";
	//cin >> dessert;
	//cin.getline(dessert, ArSize);
	cin.getline(dessert, ArSize).get();
	//当cin.get()或cin.getline()读取空行时，可以用cin.clear()恢复输入

	//cin.get(name, ArSize)会返回一个cin对象，随后被用来调用get(),与cin.getline(name, ArSize).get(dessert, ArSize)效果一样
	cout << "I have some delicious " << dessert;
	cout << "for you," << name << ".\n";//在键盘输入时，程序将（name输入）空格视为第一个字符串结束(自动加空值字符\0)，并将后面的单词读入第二个输入
	system("pause");









	//cin.get();
	//getchar();
	//system("pause");
	return 0;
}