//manip.cpp---using format manipulators
# include <iostream>

int main3()
{
	using namespace std;
	cout << "Enter an integer: ";
	int n;
	cin >> n;

	cout << "n    n*n\n";
	cout << n << "		" << n * n << "(decimal)\n";
	//set to oct mode
	cout << oct << n << "		" << n * n << "(octal)\n";
	//set to hex mode
	cout << hex;
	cout << n << "		";
	cout << "		" << n * n << "(hexadecimal)\n";

	//alternative way to call a manipulator
	dec(cout);
	cout << n << "		" << n * n << "(decimal)\n";

	system("pause");
	return 0;

}