//iomanip.cpp--------using manipulators from iomanip
//some system require explicitly linking the math library

# include <iostream>
# include <iomanip>
# include <cmath>

int main7()
{
	using namespace std;
	//using standard manipulators
	cout << fixed << right;
	//using iomanip manipulators
	cout << setw(6) << "N" << setw(14) << "square root"
		<< setw(15) << "fourth root\n";
	double root;
	for (int n = 10; n <= 100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('.') << n << setfill(' ')
			<< setw(12) << setprecision(3) << root
			<< setw(14) << setprecision(4) << sqrt(root)
			<< endl;
	}


	system("pause");
	return 0;
}