//lambda0.cpp--using lambda expressions
# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <ctime>
const long size1 = 39L;
const long size2 = 100 * size1;
const long size3 = 100 * size2;
bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }
using namespace std;


int main4()
{
	vector<int> numbers(size1);

	srand(time(0));
	generate(numbers.begin(), numbers.end(), rand);

	//using function pointers
	cout << "Sample size = " << size1 << '\n';

	int count3 = count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	int count13= count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13: " << count13 << '\n';

	//increase number of number
	numbers.resize(size2);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << size2 << '\n';
	//using a functor
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) :dv(1) {}
		bool operator()(int x) { return x % dv == 0; }
	};
	count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	count13 = count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";//'\n',"\n\n"

	//increase number of number agin
	numbers.resize(size3);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << size3 << '\n';
	//using lambdas
	count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	count13 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 13 == 0; });
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";
	count13 = 0;
	for_each(numbers.begin(), numbers.end(),
		[&count13](int x) {count13 += x % 13 == 0; });
	cout << "Count of numbers divisible by 13: " << count13 << "\n";
	cin.get();
	return 0;
}
