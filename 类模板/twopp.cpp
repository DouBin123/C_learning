# include <iostream>
# include "array.h"

int main3()
{
	using namespace std;
	ArrayTP<int, 10> sum;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;
	int m;
	cin >> m;
	cout << "hello?";
	int i, j;
	for (i = 0; i < 10; i++)
	{		
		sum[i] = 0;
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1)*(j + 1);
			sum[i] += twodee[i][j];
		}
		aves[i] = (double)sum[i] / 5;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sum[i] << ", average = " << aves[i] << endl;
	}
	cout << "Done.\n";
	system("pause");
	return 0;

}