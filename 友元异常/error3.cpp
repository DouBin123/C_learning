# include <iostream>
double hmen(double, double);
int main5()
{
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try{
			z = hmen(x, y);//start of try block
		//	std::cout << "Harmonic mean of " << x << " and " << y
		//		<< " is " << z << std::endl;
		//	std::cout << "Enter next set of numbers<q to quit>: ";

		}//end of try block
		catch (const char*s)
		{
			std::cout << s << std::endl;
			std::cout<< "Enter a new pair of numbers: ";
			continue;
		}                   //end od handler
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of numbers<q to quit>: ";
	}


	std::cout << "Bye!\n";

	system("pause");
	return 0;
}
double hmen(double a, double b)
{
	if (a == -b)
	
	  throw"bad hmen() arguments: a = -b not allowed";//执行该语句时，导致程序沿函数调用序列后退，找到try的 end of block
	
	return 2.0*a*b / (a + b);

}