# include <iostream>
using namespace std;
# include "stonewt.h"
void display(const Stonewt &st, int n);//形参为对象的函数
int main()
{
	Stonewt incognito = 275;//使用构造函数创建对象并初始化隐式转换
	Stonewt wolfe(287.5);
	Stonewt taft(21, 8);

	cout << "The celebrity weighted ";
	incognito.show_stn();
	cout << "The detective weighted ";
	wolfe.show_stn();
	cout << "The president weighted ";
	taft.show_lbs();
	incognito = 276.8;
	taft = 325;//same as taft=Stonewt(325);
	cout << "After dinner , the celebrity weighted ";
	incognito.show_stn();
	cout << "After dinner , the president weighted ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weight even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";

	//conversion fun
	Stonewt popins(9, 2.8);
	double p_wt = popins;//implicit conversion调用double（）
	cout << "Convert to double=> ";
	cout << "Popins: " << p_wt << " pounds.\n";
	cout << "Convert to int ";
	cout << "Popins: " << int(popins) << " pounds\n";
	system("pause");
	return 0;
}
void display(const  Stonewt &st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		st.show_stn();
	}

}