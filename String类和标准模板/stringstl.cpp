//stringstl.cpp----applying the  STL to a string
# include <iostream>
# include <string>
# include <algorithm>

int main17()
{
	using namespace std;
	string letters;
	cout << "Enter the letter grouping (quit to quit): ";
	while (cin >> letters&&letters != "quit")
	{
		cout << "Permutation of " << letters << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))//ÅÅÐò³É¹¦·µ»Øtrue
			cout << letters << endl;
		cout << "Enter next sequence(quit to quit): ";

	}
	cout << "Done!" << endl;


	system("pause");
	return 0;
}