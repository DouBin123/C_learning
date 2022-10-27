//copyit.cpp----copy and iterators
# include <iostream>
# include <iterator>
# include <vector>

int main10()
{
	using namespace std;

	int cats[10] = { 6, 7, 2, 3, 4, 5, 6, 7, 8, 5 };
	vector<int> dice(10);
	copy(cats, cats + 10, dice.begin());
	cout << "Let the dice be cats!\n";

	//create an ostream iterator
	ostream_iterator<int, char>   out_iter(cout, " ");
	//copy from vector to output
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "Implicit use of reverse iterator.\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "Explicit use of reverse iterator.\n";
	vector <int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;
	system("pause");
	return 0;
}