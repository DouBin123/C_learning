//get_fun.cpp--using get()and getline()
# include <iostream>
const int Limit = 255;

int main10()
{
	using namespace std;
	char input[Limit];
	cout << "Enter a string for getline() processingŁ»\n";
	cin.getline(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout << "The next input character is " << ch << endl;

	if (ch != '\n')
	{
		cin.ignore(Limit, '\n');
	}
	cout << "Enter a string for get() processsing:\n";
	cin.get(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phrase 2\n";

	cin.get(ch);
	cout << "The next input character is " << ch << endl;
	system("pause");
	return 0;
}