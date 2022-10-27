//vslice.cpp----using valarray slice
# include<iostream>
# include <valarray>
# include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;
void Show4(const vint &v, int cols);

int main20()
{
	using namespace std;
	vint valint(SIZE);

	int i;
	for (i = 0; i < SIZE; i++)
		valint[i] = rand() % 10;
	cout << "Original array:\n";
	Show4(valint, 3);
	vint vcol(valint[slice(1,4,3)]);
	cout << "Second column:\n";
	Show4(vcol, 1);
	vint vrow(valint[slice(3, 3, 1)]);
	cout << "Second row:\n";
	Show4(vrow, 3);
	valint[slice(2, 4, 3)] = 10;
	cout << "Set last column to 10:\n";
	Show4(valint, 3);
	cout << "Set first column to sum of next two:\n";
	//+not define for slice
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
	Show4(valint, 3);

	system("pause");
	return 0;

}
void Show4(const vint &v, int cols)
{
	using namespace std;
	int lim = v.size();
	for (int i = 0; i < lim; i++)
	{
		cout.width(3);
		cout << v[i];
		if (i%cols == cols - 1)
			cout << endl;
		else
			cout << ' ';

	}
	if (lim%cols != 0)
		cout << endl;

}