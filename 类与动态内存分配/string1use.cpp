# include <iostream>
# include "String1.h"
# include <ctime>
# include <cstdlib>
const int ArSize = 10;
const int MaxLen = 81;

int main2()
{
	using namespace std;
	cout << "Hi, what's your name?\n";
	String1 name;//默认构造函数
	cin >> name;//friends method "operator>>()"
	cout << name << " , please enter up to " << ArSize
		<< " short saying <empty line to quit>:\n";//friends method "operator<<()"
	String1 sayings[ArSize];//array  of object ,default constructor
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";//ostream<<
		cin.get(temp, MaxLen);//自动截取长度，存储回车
		while (cin&&cin.get() != '\n')
			continue;//未读取到回车符时还是在循环中，读取到开始下一次循环
		if (!cin || temp[0] == '\0')//检测空行,if是条件不是循环
			break;//有空行则结束for循环
		else
			sayings[i] = temp;//friend method"operator=()"

	}//将cin>>saying[i]

	int total = i; //total # of lines read
	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;//char & String1::operator[](int i)
		/*
				int shortest = 0;
				int first = 0;
				for (i = 1; i < total; i++)
				{
				if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
				if (sayings[i] < sayings[first])//friends method"operator<()"
				first = i;
				}

				cout << "Shortest saying:\n" << sayings[shortest] << endl;
				cout << "First alphabetically:\n" << sayings[first] << endl;
				cout << "This program used " << String1::HowMany()
				<< " string objects. Bye.\n";
				}
				else
				cout << "No input!Bye.\n";
				*/

		//*********************use pointers to keep track of shortest, first string
		String1 * shortest = &sayings[0];
		String1 * first = &sayings[0];
		//String1 pointers
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)//compare values
				shortest = &sayings[i];
		}
		//结构体中没有重载操作函数和构造函数因此不能直接输出结构体，而要使用下级运算符"."
		cout << "Shortest saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *sayings << endl;
		srand(time(0));
		int choice = rand() % total;
		String1 *favorite = new String1(sayings[choice]);
		cout << "My favorite saying:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "Not much to say ,eh?\n";
	cout << "Bye.\n";
	system("pause");
	return 0;

}