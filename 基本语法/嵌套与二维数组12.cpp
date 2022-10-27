# include <iostream>
using namespace std;

int main12()
{
	const int Cities = 5;
	const int Years = 4;
	const char *cities[Cities] = 
	{
		"TIANJIN", "BEIJIN", "WUHAN", "TISNDHUI", "XIAN"
	
	};
	int maxtemps[Years][Cities] =
	{
		{23,12,34,43,67},
		{34,54,21,54,23},
		{54,21,36,47,48},
		{24,13,13,35,36}
	};
	cout << "Maximum temperatures for 2008-2011\n\n";
	for (int city = 0; city < Cities; ++city)
	{
		cout << cities[city] << ":\t";
		for (int year = 0; year < Years; ++year)
		{
			cout << maxtemps[year][city] << "\t";
		}
		cout << endl;
	
	}

	system("pause");
	return 0;

}