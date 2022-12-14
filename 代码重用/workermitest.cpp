# include <iostream>
# include <cstring>
# include  "wokermi.h"
const int SIZE = 5;

int main()
{
	using namespace std;
	Worker *lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter s: singer "
			<< "t: singer waiter q:quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w ,s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': lolas[ct] = new Waiter; break;
		case 's': lolas[ct] = new Singer; break;
		case 't': lolas[ct] = new SingerWaiter; break;
		}
		cin.get();//要回车
		lolas[ct]->Set();//Worker 必须有Set(),基类指针调用+多态继承

	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";

	system("pause");
	return 0;

}