# ifndef WORKERMI_H_
#define WORKERMI_H_

#include<string>

class Worker//an ABC
{
private:
	std::string fullname;//base class
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() :fullname("no one"), id(0L){};
	Worker(const std::string &s, long n) :fullname(s), id(n){};//list initial
	virtual ~Worker() = 0;//pure virtual destructor:在基类中没有明显的函数实现，需要在派生类中实现
	virtual void Set() = 0;
	virtual void Show()const = 0;
};
//在基类定义virtual，因为为虚基类，所以只需要使用一次，而virtual恰是多态（多选一）的体现

//derived class
class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data()const;
	void Get();
public:
	Waiter() :Worker(), panache(0){};
	Waiter(const std::string &s, long n, int p = 0) :Worker(s, n), panache(p){};
	Waiter(const Worker &wk, int p = 0) :Worker(wk), panache(p){};
	void Set();
	void Show()const;

};

class Singer : virtual public Worker
{
protected:
	enum{
		other, also, contralto, soprano,
		bass, baritone, tenor
	};//声音类型
	enum{ Vtypes = 7 };
	void Data()const;
	void Get();
private:
	static char*pv[Vtypes];//c风格字符串
	int voice;

public:
	Singer() :Worker(), voice(other){};
	Singer(const std::string &s, long n, int v = other)
		:Worker(s, n), voice(v){}
	Singer(const Worker &wk, int v = other)
		:Worker(wk), voice(v){};
	void Set();
	void Show()const;

};

//multiple inheritance
class SingerWaiter :public Singer,public Waiter
{
protected:
	void Data()const;
	void Get();
public:
	SingerWaiter(){};
	SingerWaiter(const std::string &s, long n, int p = 0, int v = other)
		:Worker(s, n), Waiter(s, n, p), Singer(s, n, v){}
	SingerWaiter(const Worker &wk, int p = 0, int v = other)
		:Worker(wk), Waiter(wk, p), Singer(wk, v){}
	SingerWaiter(const Waiter &wt, int v = other) :Worker(wt), Waiter(wt), Singer(wt, v){}
	SingerWaiter(const Singer &wt, int p = 0) :Worker(wt), Waiter(wt,p), Singer(wt){}
	//没有时SingerWaiter会报错
	void Set();
	void Show()const;
};

#endif
