//# include <iostream>
//# include "work0.h"
//using std::cout;
//using std::cin;
//using std::endl;
//
////Worker method
////must implement virtual destructor ,even if pure
//Worker::~Worker(){};
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
////waiter method
//void Waiter::Set()
//{
//	Worker::Set();
//	cout << "Enter waiter's panache rating: ";
//	cin>>panache;
//	while (cin.get() != '\n')
//		continue;
//
//}
//void Waiter::Show()const
//{
//	cout << "Category: waiter\n ";
//	cout << "Panache rating : " << panache<< endl;
//
//}
////Singer method
//char* Singer::pv[] = { "other", "alto", "contralto", "soprano",
//					"bass", "baritone", "tenor" };
//void Singer::Set()
//{
//	Worker::Set();
//	cout << "Enter number for singer's vocal range:\n";
//	int i ;
//	for(i= 0; i < Vtypes;i++ )
//	{
//		cout << i << " : " << pv[i] << "  ";
//		if (i % 4 == 3)//ÿ4�����У�i%n==n-1��:ÿn������
//			cout << endl;
//	}
//	if (i % 4 != 0)//���һ���������4����
//		cout << endl;
//	while (cin >> voice && (voice < 0 || voice >= Vtypes))//���벻���Ϲ淶ʱ
//		cout << "Please enter a value >=0 and<"<< Vtypes << endl;
//	while (cin.get() != '\n')
//		continue;
//}
//void Singer::Show()const
//{
//	cout << "Category: singer\n ";
//	cout << "vocal range : " <<pv[voice] << endl;
//
//}
