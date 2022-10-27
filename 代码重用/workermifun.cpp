# include <iostream>
# include "wokermi.h"
using std::cout;
using std::cin;
using std::endl;

//Worker method
//must implement virtual destructor ,even if pure
Worker::~Worker(){};
//protected method
void Worker::Data()const
{
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID : " << id << endl;
}
void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
//纯虚函数
//void Worker::Set()
//{
//	cout << "Enter worker's name: ";
//	getline(cin, fullname);
//	cout << "Enter worker's ID: ";
//	cin >> id;
//	while (cin.get() != '\n')
//		continue;
//
//}
//void Worker::Show()const
//{
//	cout << "Name: " << fullname << "\n";
//	cout << "Employee ID : " << id << endl;
//
//}
//waiter method
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();

}
void Waiter::Show()const
{
	cout << "Category: waiter\n ";
	Worker::Data();
	Data();
}
//protected method
void Waiter::Data()const
{
	cout << "Panache rating: " << panache << endl;
}
void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}
//Singer method
char* Singer::pv[] = { "other", "alto", "contralto", "soprano",
"bass", "baritone", "tenor" };
void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}


void Singer::Show()const
{
	cout << "Category: singer\n ";
	Worker::Data();
	Data();
}
//protected method
void Singer::Data()const
{
	cout << "Vocal range: " << pv[voice] << endl;
}
void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << " : " << pv[i] << "  ";
		if (i % 4 == 3)//每4个换行（i%n==n-1）:每n个换行
			cout << endl;
	}
	if (i % 4 != 0)//最后一行输出不足4换行
		cout << endl;
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}
//SingerWaiter methods
void SingerWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();

}
void SingerWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
void SingerWaiter::Set()
{
	cout << "Enter singer waiter's name: ";
	Worker::Get();
	Get();
}
void SingerWaiter::Show()const
{
	cout << "Category: singer waiter\n";
	Worker::Data();
	Data();

}