# include <iostream>
# include <cmath>
# include "exc_mean.h"

double hmean(double, double);
double gmean(double, double);

int main6()
{
	using namespace std;

	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z <<endl;
			cout << "Geomertric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}//end of try block
		catch (bad_hmen &bg)//start of catch block
		{
			bg.mesg();
			cout << "Try agin.\n";
			continue;
		}
		catch (bad_gmean &hg)
		{
			cout << hg.mesg();
			cout << "Values usd: " << hg.v1 << ", "
				<< hg.v2 << endl;
			cout << "Sorry,you don't get to play any more.\n";
			break;//quit while()
		}//end of catch block
		int a = 4, b = 5;
		cout << "a+b= " << a + b;
	}
	cout << "Bye!\n";

	system("pause");
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmen(a, b);
	return 2.0*a*b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0|| b <0 )
		throw bad_gmean(a, b);
	return std::sqrt(a*b);
}