# include <iostream>
# include <cfloat>//for DBL_MAX

bool hmen(double a, double b, double *ans);

int main4()
{



	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		if (hmen(x, y, &z))

			std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		else
			std::cout << "One value should not be the negative "
			<< "of the other - try agin.\n";
		std::cout << "Enter next set of numbers<q to quit>: ";
	}
	std::cout << "Bye!\n";

	system("pause");
	return 0;
}
bool hmen(double a, double b, double *ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0*a*b / (a + b);
		return true;
	}
}