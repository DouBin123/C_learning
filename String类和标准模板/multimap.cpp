# include <iostream>
# include <map>
# include <string>
# include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string>MapCode;

int main13()
{
	using namespace std;
	MapCode codes;

	codes.insert(Pair(415, "San Franciso"));
	codes.insert(Pair(510, "Oakland"));
	codes.insert(Pair(718, "Brooklyn"));
	codes.insert(Pair(718, "Sate Island"));
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(Pair(510, "Berkeley"));
	codes.insert(Pair(718, "Datrs Island"));

	cout << "Number of cities wth area code 415: "
		<< codes.count(415) << endl;
	cout << "Number of cities with area code 718: "
		<< codes.count(718) << endl;
	cout << "Number of cities with area code 510: "
		<< codes.count(510) << endl;
	cout << "Area Code City\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); it++)
		cout << "  " << (*it).first << "   "
		<< (*it).second << endl;//first 访问第一个元素(键)，second访问第二个元素(值)
	pair<MapCode::iterator, MapCode::iterator> range
		= codes.equal_range(718);
	cout << "Cities with area code 718:\n";
	for (it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;


	system("pause");
	return 0;
}

