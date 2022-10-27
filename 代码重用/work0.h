# ifndef WORKER0_H_
#define WORKER0_H_

#include<string>

class Worker//an ABC
{
private:
	std::string fullname;//base class
	long id;
public:
	Worker() :fullname("no one"), id(0L){};
	Worker(const std::string &s, long n) :fullname(s), id(n){};//list initial
	virtual ~Worker() = 0;//pure virtual destructor:在基类中没有明显的函数实现，需要在派生类中实现
	virtual void Set();
	virtual void Show()const;
};

//derived class
class Waiter :public Worker
{
private:
	int panache;

public:
	Waiter() :Worker(), panache(0){};
	Waiter(const std::string &s, long n, int p = 0) :Worker(s, n), panache(p){};
	Waiter(const Worker &wk, int p = 0) :Worker(wk), panache(p){};
	void Set();
	void Show()const;

};

class Singer :public Worker
{
protected:
	enum{other,also,contralto,soprano,
	bass,baritone,tenor};//声音类型
	enum{Vtypes=7};
private:
	static char*pv[Vtypes];//c风格字符串
	int voice;

public:
	Singer() :Worker(), voice(other){};
	Singer(const std::string &s, long n, int v = other)
		:Worker(s, n), voice(v){}
	void Set();
	void Show()const;

};

#endif