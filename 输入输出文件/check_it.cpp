//check_it.cpp----checking for valid input
# include <iostream>

int main8()
{
	using namespace std;
	cout << "Enter numbers: ";

	int sum = 0;
	int input;
	while (cin >> input)//遇到不匹配的循环终止
	{
		sum += input;
	}
	
	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;
	if (cin.fail() && !cin.eof())//failed because of mismatched input
	{
		cin.clear();
		while (!isspace(cin.get()))
			continue;//get rid of bad input   ，cin会创建一个输入流  
	}
	else //else bail out
	{
		cout << "I cannot go on!\n";
		exit(1);
	}
	cout << "Now enter a new number: ";
	cin >> input;

	system("pause");
	return 0;
}