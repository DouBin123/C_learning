//useless.cpp----an otherwise useless calss with move semantics
# include <iostream>
using namespace std;
//interface
/*
#pragma region useless
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
	Useless operator + (const Useless & f)const;
	//need operator=() in copy and move versions
	void showdata()const;
};

//implementation
int Useless::ct = 0;//在函数之外，还属于类的定义
Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	cout << "default constructor called ;number of objects: " << ct << endl;
	showobject();
}
Useless::Useless(int k) :n(k)
{
	++ct;
	cout << "int constructor called;number of objects " << ct << endl;
	pc = new char[n];
	showobject();
}
Useless::Useless(int k,char ch) :n(k)
{
	++ct;
	cout << "int ,char constructor called;number od objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
	showobject();

}
Useless::Useless(const Useless& f) :n(f.n)
{
	++ct;
	cout << "copy const called;number od objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	showobject();
}

Useless::Useless( Useless&& f) :n(f.n)
{
	++ct;
	cout << "move const called;number od objects: " << ct << endl;
	pc = f.pc;//steal address
	f.pc = nullptr;//give old object nothing in return
	f.n = 0;
	showobject();
}
Useless::~Useless()
{
	cout << "destructor called; objects left: " << --ct << endl;
	cout << "deleted object:\n";
	showobject();
	delete[]pc;
}
Useless Useless::operator+(const Useless& f)const
{
	cout << "Entering opertor+()\n";
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];
	cout << "temp object:\n";
	cout << "leaving operator+()\n";
	return temp;
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
#pragma endregion 
*/
//application
int main2()
{
	{
		/*
		Useless one(10, 'x');//1
		Useless two = one;//2  copy
		Useless three(20, 'o');//3
		Useless four(one + three);//4,operator+() 5，&&，delete（4） 4
		//4 和 5 对象所指的地址相同，使用移动构造函数，右值移动语义将4所指对象的所有权转让给5，并将4置空
		cout << "object one: ";
		one.showdata();
		cout << "object two: ";
		two.showdata();
		cout << "object three: ";
		three.showdata();
		cout << "object four: ";
		four.showdata();
	
	*/
	}
	cin.get();
	return 0;
}