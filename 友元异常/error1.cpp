# include <iostream>
# include <cstdlib>

double hmen1(double a, double b);//function declaration

int main3()
{
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		z = hmen1(x, y);
		std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		std::cout << "Enter next set of numbers<q to quit>: ";
	}
	std::cout << "Bye!\n";

	system("pause");
	return 0;

}
double hmen1(double x, double y)
{
	if (x == -y)
	{
		std::cout << "untennable arguments to hmen()\n";
		std::abort();//³ÌÐòÒì³£
	}
	return 2.0*x*y / (x + y);

}