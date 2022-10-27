//width.cpp--using the width method
# include <iostream>

int main4()
{
	using namespace std;
	cout.fill('&');//¸Ä±äÌî³ä×Ö·û
	int w = cout.width(30);
	cout << "default field width=" << w << ":\n";
	cout.width(5);
	cout << "N" << ':';
	cout.width(8);
	cout << "N*N" << ":\n";

	for (long i=1; i <=100; i*=10)
	{
		cout.width(5);
		cout << i << ':';
		cout.width(8);
		cout << i * i << ":\n";

	}


	system("pause");
	return 0;
}