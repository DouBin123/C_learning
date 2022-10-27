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
String1::String1(const char *s)//�β��൱�ڶ���
{
	len = std::strlen(s);//��������\0��
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
	delete[] str;//ɾ����������ֵ�Ķ�����֮ǰ�Ĵ洢�ĵ�ַ���ͷ��ڴ�
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

//overloading friends method,���Ի������
bool operator<(const String1 &st1, const String1 &st)
{
	return(strcmp(st1.str, st.str) < 0);

}
/*
strcmp()�����Ǹ���ACSII���ֵ���Ƚ������ַ����ģ�
strcmp()�������Ƚ�s1�ַ����ĵ�һ���ַ�ֵ��ȥs2��һ���ַ���
����ֵΪ��������Ƚ���ȥ������ֵ��Ϊ�㣬�򷵻ز�ֵ��
�������ֵС�� 0�����ʾ str1 С�� str��
�������ֵ���� 0�����ʾ str1 ���� str��
�������ֵ���� 0�����ʾ str1 ���� str��
*/
bool operator>(const String1 &st1, const String1 &st)
{
	return st<st1;

}
bool operator==(const String1 &st1, const String1 &st)
{
	 return strcmp(st1.str, st.str)== 0;

}
ostream & operator<<(ostream &os, const String1& st)//������ԭ������һ��
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