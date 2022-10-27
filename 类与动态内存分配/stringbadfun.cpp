# include <iostream>
# include <string>
# include"String1.h"
using namespace std;

//static method
int String1::HowMany()
{
	return num_strings;
}


//initializing static class member
int String1::num_strings = 0;

//class method
String1::String1(const char *s)//形参相当于定义
{
	len = std::strlen(s);//不包含‘\0’
	str = new char[len + 1];//allot storage
	strcpy(str, s);//initialize pointer
	num_strings++;//set object count(common parameter)
	cout << num_strings << " : \"" << str << " \" object created\n";
}
String1::String1(const String1 &st)
{
	num_strings++;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
	cout << num_strings << " : \"" << str << " \" object created\n";
}
String1::String1()
{
	len = 4;
	str = new char[1];
	str[0]='\0';//defaul string
	num_strings++;//set object count(common parameter)
	cout << num_strings << " : \"" << str << " \" object created\n";
}
String1::~String1()
{
	cout << " \"" << str << " \" object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete[]str;
}

//overloading method
String1 & String1::operator=(const String1 &st)
{
	if (this == &st)
		return *this;
	delete[] str;//删除即将被赋值的对象中之前的存储的地址，释放内存
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
//assign a C string to a String object
String1 & String1::operator=(const char*s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
//read-write char access for non-const String
char & String1::operator[](int i)
{
	return str[i];
}

//overloading friends method,可以互相调用
bool operator<(const String1 &st1, const String1 &st)
{
	return(strcmp(st1.str, st.str) < 0);

}
/*
strcmp()函数是根据ACSII码的值来比较两个字符串的；
strcmp()函数首先将s1字符串的第一个字符值减去s2第一个字符，
若差值为零则继续比较下去；若差值不为零，则返回差值。
如果返回值小于 0，则表示 str1 小于 str。
如果返回值大于 0，则表示 str1 大于 str。
如果返回值等于 0，则表示 str1 等于 str。
*/
bool operator>(const String1 &st1, const String1 &st)
{
	return st<st1;

}
bool operator==(const String1 &st1, const String1 &st)
{
	 return strcmp(st1.str, st.str)== 0;

}
ostream & operator<<(ostream &os, const String1& st)//与声明原型类型一样
{
	os << st.str;
		return os;
}
istream & operator>>(istream &is,  String1 & st)
{
	char temp[String1::CINLIM];
	is.get(temp, String1::CINLIM);//cin.get(arr,arr_size)
	if (is)
		st=temp;
	while (is&&is.get() != '\n')
		continue;
	return is;

}