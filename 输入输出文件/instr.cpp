//instr.cpp---formatted reading from a char array
# include <iostream>
# include <sstream>
# include<string>

int main()
{
	using namespace std;
	string lit = "It was a dark and stormy day,and "
		" the full moon glowed brilliantly. ";
	istringstream instr(lit);//use buf for input
	string word;
	while (instr >> word)//read the string
		cout << word << endl;

	system("PAUSE");
	return 0;
}