# include <iostream>
# include "stack.h"

int main()
{
	using std::cin;
	using std::cout;
	Stack st;//根据默认构造函数创建空栈
	char ch;
	unsigned long po;
	std::cout << "Please enter A to add a purchase order,\n"
		<< "P to process a P0,or Q to quit.\n";
	while (cin >> ch&&toupper(ch) != 'Q')//(((cin >> ch)&&toupper(ch)) != 'Q')
	//输入如果是其他字母则程序重新由这里执行
	{
		while (cin.get() != '\n')//不是回车符继续下一个输入
			continue;
		if (!isalpha(ch))
		{
			std::cout << '\a';//警告
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':cout << "Enter a P0 number to add: ",
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':if (st.isempty())
			cout << "stack already empty\n";
				 else
				 {
					 st.pop(po);
					 cout << "P0 # " << po << "popped\n";
				 }
				 break;
		}
		cout << "Please enter A to add a purchase order,\n "
			<< "p to process a P0, or Q to quit.\n";
	}
	cout << " Bye\n";
	



	std::system("pause");
	return 0;
}