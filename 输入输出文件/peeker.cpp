//peeker.cpp--some istream method
# include <iostream>

int main11()
{
	using namespace std;
	//read and echo input up to a # character
	char ch;
	while (cin.get(ch))
	{
		if (ch != '#')
			cout << ch;
		else
		{
			cin.putback(ch);//reinsert character
			break;
		}
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << "is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		std::exit(0);
	}
	while (cin.peek() != '#')//look ahead,continue the program processing

	{
		cin.get(ch);
		cout << ch;
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
		cout << "End of file reached.\n";

	system("pause");
	return 0;
}