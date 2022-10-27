# include "sales.h"
using namespace std;

Sales::bad_index::bad_index(int ix, const string &s)
	:std::logic_error(s), bi(ix)
{
}
Sales::Sales(int yy)
{
	year = yy;
	for (int i = 0; i < MONTH; i++)
	{
		gross[i] = 0;
	}
}

Sales::Sales(int yy, const double *gr, int n)
{
	year = yy;
	int i;
	int lim = (n < MONTH) ? n : MONTH;
	for (i = 0; i < lim; i++)
		gross[i] = gr[i];
		gross[i] = 0;
}
double Sales::operator[](int i)const
{
	if (i<0 || i>MONTH)
		throw bad_index(i);
	return gross[i];

}
double &Sales::operator[](int i)
{
	if (i<0 || i>MONTH)
		throw bad_index(i);//bad_index(i)如果构造函数参数为两个，可以将第二个参数列表初始化设为常值
	return gross[i];
}
LabeledSales::nbad_index::nbad_index(const string &lb,int ix,
	const string &s) :Sales::bad_index(ix, s)
{
	lb1 = lb;

}
LabeledSales::LabeledSales(const string &lb, int yy) :Sales(yy)
{
	label = lb;
}
LabeledSales::LabeledSales(const string &lb, int yy,
	const double *gr, int n) : Sales(yy, gr, n)
{
	label = lb;
}

double LabeledSales::operator[](int i)const//右值及引用
{
	if (i<0 || i>MONTH)
		throw nbad_index(Label(),i);
	return
		Sales::operator[](i);
}
double  &LabeledSales::operator[](int i)//左值
{
	if (i<0 || i>MONTH)
		throw nbad_index(Label(), i);
	return
		Sales::operator[](i);
}