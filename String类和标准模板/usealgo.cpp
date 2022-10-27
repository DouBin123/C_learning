//usealgo.cpp----using several STL elements
# include <iostream>
# include <string>
# include <vector>
# include <set>
# include <map>
# include <iterator>
# include <algorithm>
# include <cctype>
using namespace std;

char toLower(char ch){ return tolower(ch); }
string &ToLower(string &st);
void display(const  string &s);

int main18()
{
	vector<string>words;
	cout << "Enter words(quit to quit):\n";
	string input;
	while (cin >> input&&input != "quit")
		words.push_back(input);

	cout << "You entered the following words:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	//place words in set ,converting to lowercase
	set<string>wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
	//words.begin(), words.end():源
	//insert_iterator<set<string>>(wordset, wordset.begin()):目标
	//ToLower：方法
	cout << "\nAlphabetic list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	//place word and frequency in map

	map<string, int>wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);//查找map中键值为*si的值的个数

	//display map contents
	cout << "\nWord frequency:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ":" << wordmap[*si] << endl;

	system("pause");
	return 0;
}
string &ToLower(string &st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;

}
void display(const string &s)
{
	cout << s << " ";
}