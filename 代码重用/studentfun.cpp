//# include "studentc.h"
//using namespace std;
//
////public
//double Student::Average()const
//{
//	if (scores.size() > 0)
//		return scores.sum() / scores.size();
//	else
//		return 0;
//
//}
//const string & Student::Name()const
//{
//	return name;
//
//}
//double Student::operator[](int i)const//ֻ��
//{
//	return scores[i];
//
//}
//double & Student::operator[](int i)//д
//{
//	return scores[i];
//
//}
////private
////valarrayû��operator<<()����
//ostream & Student::arr_out(ostream &os)const
//{
//	int i;
//	int lim = scores.size();
//	if (lim > 0)
//	{
//		for (i = 0; i < lim; i++)
//		{
//			os << scores[i] << " ";
//			if (i % 5 == 4)//5��һ��
//				os << endl;
//		}
//		if (i % 5 != 0)//����5�����������У�����5
//			os << endl;
//	}
//	else
//		os << " empty array";
//	return os;
//}
////friend
////use string version of operator>>()
//istream &operator>>(istream &is, Student &stu)
//{
//	is >> stu.name;
//	return is;
//
//}
////use string friend getline(istream &,string &)
//istream & getline(istream &is, Student &stu)
//{
//	getline(is,stu.name);
//	return is;
//
//}
////use string version of operator<<()
//ostream & operator<<(ostream &os, const Student &stu)
//{
//	os << "Scores for " << stu.name << ":\n";
//	stu.arr_out(os);
//	return os;
//
//}