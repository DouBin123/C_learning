# include <iostream>

class bad_hmen
{
private:
	double v1;
	double v2;
public:
	bad_hmen(double a = 0, double b = 0) :v1(a), v2(b){}
	void mesg();
};
inline void bad_hmen::mesg()
{
	std::cout << "hmen(" << v1 << ", " << v2 << "): "
		<< "invalid arguments: a = - b\n";
}

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0,double b = 0):v1(a), v2(b){}
	const char* mesg();
};
inline const char*bad_gmean::mesg()
{
	return "gmean()arguments should be >=0\n";

}