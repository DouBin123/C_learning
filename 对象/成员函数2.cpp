# include <iostream>
# include "stock00.h"
//���캯��
Stock::Stock()
{
	std::cout << "Default constructor called\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negtive; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();

}
Stock::~Stock()
{
	std::cout << "Bye, " << company << "!\n";

}
//other method
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negtive."
			<< "Transaction is absorted.\n";

	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();

	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares sold can't be negtive."
			<< "Transaction is absorted.\n";

	}
	else if (num > shares)
	{
		std::cout << "You can't sell more than you have!"
			<< "Transaction is absorted.\n";
	}

	else
	{
		shares += num;
		share_val = price;
		set_tot();

	}
}
void Stock::update(double price)
	{
	share_val = price;
	set_tot();
	
	}
void Stock::show()const
{
	using std::cout;
	using std::ios_base;
	//set format to ##.###
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	std::cout << "Company : " << company
		<< " shares: " << shares << '\n';
	cout << " shares price: $ " << share_val;
	//set format to ##.##	
	cout.precision(2);
	cout<< " total worth: $ " << total_val << '\n';
	//restore original format
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
const Stock &Stock::topval(const Stock & s) const//����һ�������޸ĵĶ�������ã������޸���ʽ���ʵĶ��󣬵��ó�Ա�����Ķ��󲻿��޸�
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;//����ֵΪ���󣬲��ǵ�ַ

}