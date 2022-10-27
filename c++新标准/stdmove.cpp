//stdmove.cpp--using std::move
# include <iostream>
# include <utility>
using namespace std;
//interface
class Useless
{
private:
	int n;
	char* pc;
	static int ct;
	void showobject()const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless& f);
	Useless(Useless&& f);
	~Useless();
	Useless operator + (const Useless& f)const;
	//need operator=() in copy and move versions
	Useless& operator = (const Useless& f);//copy
	Useless& operator=(Useless&& f);//move
	void showdata()const;
};

//implementation
int Useless::ct = 0;//在函数之外，还属于类的定义
Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
}
Useless::Useless(int k) :n(k)
{
	++ct;
	pc = new char[n];

}
Useless::Useless(int k, char ch) :n(k)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
}
Useless::Useless(const Useless& f) :n(f.n)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
}

Useless::Useless(Useless&& f) :n(f.n)
{
	++ct;
	pc = f.pc;//steal address
	f.pc = nullptr;//give old object nothing in return
	f.n = 0;
}
Useless::~Useless()
{
	delete[]pc;
}
Useless Useless::operator+(const Useless& f)const
{
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];
	return temp;
}
Useless& Useless::operator=(const Useless& f)
{
	cout << "copy assignment operator called:\n";
	if (this == &f)
		return *this;
	delete[]pc;
	n = f.n;
	pc = new char[n];//新申请了一块内存
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	return *this;
}

Useless& Useless::operator=(Useless&& f)
{
	cout << "move assignment operator called:\n";
	if (this == &f)
		return *this;
	delete[]pc;
	n = f.n;
	pc = f.pc;//改变所有权
	f.n = 0;
	f.pc = nullptr;
	return *this;
}

void Useless::showobject()const
{
	cout << "Number of elements: " << n;
	cout << " Data address: " << (void*)pc << endl;
}
void Useless::showdata()const
{
	if (n == 0)
		cout << " (object empty)";
	else
		for (int i = 0; i < n; i++)
			cout << pc[i];
	cout << endl;
}
//application
int main3()
{
	{
		Useless one(10, 'x');
		Useless two = one + one;//move
		cout << "object one: ";
		one.showdata();
		cout << "object two: ";
		two.showdata();
		Useless three, four;
		cout << "three= one\n";
		three = one;//move
		cout << "now object three = ";
		three.showdata();
		cout << "and object one = ";
		one.showdata();
		cout << "four=one+two\n";
		four = one + two;
		cout << "now object four = ";
		four.showdata();
		cout << "and object one = ";//右值为one + two，删除的是该对象的内容
		one.showdata();
		cout << "four=move(one)\n";
		four = std::move(one);
		cout << "now object four = ";
		four.showdata();
		cout << "and object one = ";//右值为one，将指针置空，清空数据
		one.showdata();
	}
	cin.get();
	return 0;
}
