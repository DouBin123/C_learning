//wrapped.cpp--using a function wrapper as an argument
# include "somedefs.h"
# include <iostream>
# include <functional>

double dub1(double x) { return 2.0 * x; }
double square1(double x) { return x * x; }

int main6()
{
	using namespace std;
	double y = 1.2;
	function<double(double)> ef1 = dub1;
	//临时对象
	//typedef function<double(double)> fdd
	//fdd(dub)

	/*
	teplate <typename T>
	T use_f(T v,std::function<T(T)> f)
	{
		函数体；
	}
	use_f<double>(y,dub)
	std::function<T(T)>     std::function<double(double)>
	*/
	function<double(double)> ef2 = square1;
	function<double(double)> ef3 = Fq(10.0);
	function<double(double)> ef4 = Fp(10.0);
	function<double(double)> ef5 = [](double u) {return u * u; };
	function<double(double)> ef6 = [](double u) {return u+u/2.0; };
	cout << "Function pointer dub:\n";
	cout << " " << use_f(y, ef1) << endl;
	cout << "Function pointer square:\n";
	cout << " " << use_f(y, ef2) << endl;
	cout << "Function object Fp:\n";
	cout << " " << use_f(y, ef4) << endl;
	cout << "Function object Fq:\n";
	cout << " " << use_f(y, ef3) << endl;
	cout << "Lambda expression 1:\n";
	cout << " " << use_f(y, ef5) << endl;
	cout << "Lambda expression 2:\n";
	cout << " " << use_f(y, ef6) << endl;
//count 1,2,3,4,5,6  1个地址，函数调用6次，只有一个实例
	return 0;
}