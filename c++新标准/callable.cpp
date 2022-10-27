//callable.cpp--callable types and templates
# include <iostream>
# include "somedefs.h"

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }
int main5()
{
	using std::endl;
	using::std::cin;
	using std::cout;

	double y = 1.21;
	cout << "Function pointer dub:\n";
	cout << " " << use_f(y, dub) << endl;
	cout << "Function pointer square:\n";
	cout << " " << use_f(y, square) << endl;
	cout << "Function object Fp:\n";
	cout << " " << use_f(y, Fp(5.0)) << endl;
	cout << "Function object Fq:\n";
	cout << " " << use_f(y, Fq(5.0)) << endl;
	cout << "Lambda expression 1:\n";
	cout << " " << use_f(y, [](double u) {return u * u; } )<< endl;
	cout << "Lambda expression 2:\n";
	cout << " " << use_f(y, [](double u) {return u * u/2.0; }) << endl;
	cin.get();
	return 0;
	//count 1,2,1,1,1,1 5����ַ��5��ʵ��
}