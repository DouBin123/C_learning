//strout.cpp---incore formatting(output)
# include <iostream>
# include <sstream>
# include <string>

int main17()
{
	using namespace std;
	ostringstream outstr;
	string hdisk;
	cout << "What's the name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "What's its capacity in GB? ";
	cin >> cap;
	//write formatting information to string stream
	outstr << "The hard disk " << hdisk << " has a capacity of "
		<< cap << " gigabytes.\n";
	string result = outstr.str();
	cout << result;

	system("pause");
	return 0;
}