//cinexcp.cpp--having cin throw an exception
# include <iostream>
# include <exception>

int main9()
{
	using namespace std;
	//have failbit cause an exception to be thrown
	cin.exceptions(ios_base::failbit);
	cout << "Enter numbers:  ";
	int sum = 0;
	int input;
	try
	{
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure& bf)
	{
		cout << bf.what() << endl;
		cout << "O! the horro!\n";
	}
	cout << "Last value entered = " << input << endl;
	cout << "SUM = " << sum << endl;
	system("pause");
	return 0;
}