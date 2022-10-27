# include <iostream>
# include <list>
# include <iterator>
# include <algorithm>

template <class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T&t) :cutoff(t){}
	bool operator()(const T&v){ return v > cutoff; }
};

void outint2(int n){ std::cout << n << " "; }

int main14()
{
	using namespace std;
	TooBig <int>f100(100);
	int val[10] = { 50, 100, 90, 180, 60, 210, 425, 8, 88, 201 };
	list<int>yadayada(val, val + 10);
	list<int>etcetera(val, val + 10);

	cout << "Original list:\n";
	for_each(yadayada.begin(), yadayada.end(), outint2);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint2);
	cout << endl;
	yadayada.remove_if(f100);//接收的是bool量，这里是使用了函数符
	etcetera.remove_if(TooBig<int>(200));
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint2);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint2);
	cout << endl;

	system("pause");
	return 0;
}