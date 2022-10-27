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
	String1 name;//Ĭ�Ϲ��캯��
	cin >> name;//friends method "operator>>()"
	cout << name << " , please enter up to " << ArSize
		<< " short saying <empty line to quit>:\n";//friends method "operator<<()"
	String1 sayings[ArSize];//array  of object ,default constructor
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";//ostream<<
		cin.get(temp, MaxLen);//�Զ���ȡ���ȣ��洢�س�
		while (cin&&cin.get() != '\n')
			continue;//δ��ȡ���س���ʱ������ѭ���У���ȡ����ʼ��һ��ѭ��
		if (!cin || temp[0] == '\0')//������,if����������ѭ��
			break;//�п��������forѭ��
		else
			sayings[i] = temp;//friend method"operator=()"

	}//��cin>>saying[i]

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
		//�ṹ����û�����ز��������͹��캯����˲���ֱ������ṹ�壬��Ҫʹ���¼������"."
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