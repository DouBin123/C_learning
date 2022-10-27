# include <iostream>
#ifndef String1_H_
#define String1_H_
using std::ostream;
using std::istream;

class String1
{

private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String1();
	String1(const String1 &);//复制构造函数
	String1(const char*s);
	~String1();
	int length() const{ return len; }//调用该方法的对象只读
	
	//overloading operator method
	String1 & operator=(const String1 &);
	String1 & operator=(const char *);
	char & operator[](int i);

	//overloading operator friends(two elements)
	friend bool operator<(const String1 &st, const String1 &st2);
	friend bool operator>(const String1 &st, const String1 &st2);
	friend bool operator==(const String1 &st, const String1 &st2);
	friend ostream & operator<<(ostream &os, const String1 &st);
	friend istream & operator>>(istream &is,  String1 &st);//String1 &st 必须可以修改 
	//static function
	static int HowMany();


};


#endif