# include <iostream>
# include <cstdlib>
# include <ctime>
# include <typeinfo>
using namespace std;

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) :hold(h){}
	virtual void Speak()const { cout << "I am a grand class!\n"; }
	virtual int Value()const { return hold; }
};

class Superb :public Grand
{
public:
	Superb(int h = 0) :Grand(h){}
	void Speak()const{ cout << "I am a superb class!\n"; }
	virtual void Say()const
	{
		cout << "I hold  the superb value of " << Value() << "!\n";
	}
};
class Magnification : public Superb
{
private:
	char ch;
public:
	Magnification(int h = 0, char cv = 'A') :Superb(h), ch(cv){}
	void Speak()const { cout << "I am a magnification!\n"; }
	void Say()const { cout << "I hold the character " << ch << " and the integer " << Value()<<" !\n"; }
};

Grand * Getone1();

int main11()
{
	srand(time(0));//随机数种子更新
	Grand *pg;
	Superb *ps;
	for (int i = 0; i < 5; i++)
	{
		pg = Getone1();
		cout << "Now processing type " << typeid(*pg).name() << ".\n";
		pg->Speak();
		if (ps = dynamic_cast<Superb *>(pg))//pg能否转换为Superb对象类型
			ps->Say();
		if (typeid(Magnification) == typeid(*pg))//不能基类隐式转换
			cout << "Yes.you're really magnification.\n";
	}
	system("pause");
	return 0;
}

Grand *Getone1()
{
	Grand * p = 0;
	switch (std::rand() % 3)
	{
	case 0: p = new Grand(std::rand() % 100);
		break;
	case 1: p = new Superb(std::rand() % 100);
		break;
	case 2: p = new Magnification(std::rand() % 100, 'A' + std::rand() % 26);
		break;
	}
	return p;
}