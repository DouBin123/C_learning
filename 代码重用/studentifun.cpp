# include "studenti.h"
using namespace std;

//public
double Student::Average()const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;

}
const string & Student::Name()const
{
	return (const string &)*this;//���������Ϊ�����ǿ������ת��

}
double Student::operator[](int i)const//ֻ��
{
	return ArrayDb::operator[](i);

}
double & Student::operator[](int i)//д
{
	return ArrayDb::operator[](i);

}
//private
//valarrayû��operator<<()����
ostream & Student::arr_out(ostream &os)const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i)<< " ";
			if (i % 5 == 4)//5��һ��
				os << endl;
		}
		if (i % 5 != 0)//����5�����������У�����5
			os << endl;
	}
	else
		os << " empty array";
	return os;
}
//friend
//use string version of operator>>()
istream &operator>>(istream &is, Student &stu)
{
	is >> (string &)stu;
	return is;

}
//use string friend getline(istream &,string &)
istream & getline(istream &is, Student &stu)
{
	getline(is, (string &)stu);
	return is;

}
//use string version of operator<<()
ostream & operator<<(ostream &os, const Student &stu)
{
	os << "Scores for " << (string &)stu << ":\n";
	stu.arr_out(os);
	return os;

}