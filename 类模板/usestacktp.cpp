# include <iostream>
# include <string>
# include <cctype>
# include "stacktp.h"
using namespace std;

int main1()
{
	Stack<std::string> st;//create an empty stack
	char ch;
	string po;
	cout << "Please enter A to add a purchase order ,\n"
		<< "P to process a PO,or Q to quit.\n";
	while (cin>>ch&&std::toupper(ch)!='Q')//输入其他字母在这里循环
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << "\a";//alarming
			continue;
		}
		switch (ch)
		{
		case 'A'://A,a
		case 'a':cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
				break;
		case 'P'://p,P
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " poped\n";
			break;
			}
		}
		cout << "Please enter A to add a purchase order ,\n"
			<< "P to process a PO,or Q to quit.\n";
	}
	cout << "Bye.\n";
	system("pause");
	return 0;

}