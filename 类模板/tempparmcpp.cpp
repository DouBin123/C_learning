# include <iostream>
# include"stacktp.h"

template <template<typename  T>class Thing>//template<typename  T>class Thing :Ä£°åÀàclass Thing
class Crab
{
private:
	Thing<int>s1;
	Thing<double>s2;
public:
	Crab(){};
	bool push(int a, double x){ return s1.push(a) && s2.push(x); }
	bool pop(int &a, double &x){ return s1.pop(a) && s2.pop(x); }
};
int main5()
{
	using namespace std;
	Crab<Stack>nebula;
//Stack must match template<typename T>class Thing

	int ni;
	double nd;
	cout << "Enter int double pairs ,such as 4 3.5 (0 0 to end): \n";
	while (cin >> ni >> nd&&ni > 0 && nd > 0)
	{
		if (!nebula.push(ni, nd))
			break;
	}
	while (nebula.pop(ni, nd))
		cout << ni << " , " << nd << endl;
	cout << "Done.\n";
	
	system("pause");
	return 0;

}