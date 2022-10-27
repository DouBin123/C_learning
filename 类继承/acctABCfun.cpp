# include <iostream>
# include"accabc.h"
# include<string>
using namespace std;

//ABCclass
AcctABC::AcctABC(const string &s, long an, double bal)
{
    FullName = s;
	acctnum = an;
	balance = bal;

}
void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "Neqative deposit not allowed; "
		<< "deposit is cancelled.\n";
	else
		balance += amt;//结余

}
void AcctABC::Withdraw(double amt)
{
	balance -= amt;

}
AcctABC::Formatting AcctABC::setformat()const//const? 后面加 const表示函数不可以修改class的成员
{
	//set up ###.##
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}
void AcctABC::restore(Formatting &f)const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);

}

//Brass method
void Brass::Withdraw(double amt)
{
	if (amt < 0)
	{
		cout << "Withdraw amount must be positive; "
			<< "withdraw cancelled.\n";
	}
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Withdraw amount of $" << amt
		<< " exceeds your balance.\n"
		<< "Withdraw cancelled.\n";
}
void Brass::ViewAcct()const
{
	Formatting f = setformat();
	cout << "Brass Client: " << fullname() << endl;
	cout << "Account Number: " << Acctnum() << endl;
	cout << "Balance : $" << Balance() << endl;
	restore(f);

}

//BrassPlus method
BrassPlus::BrassPlus(const string &s, long an, double bal,double ml, double r) :AcctABC(s, an, bal)

{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;

}
BrassPlus::BrassPlus(const Brass & ba, double ml , double r ) :AcctABC(ba)//use implicit copy constructor
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;

}
void BrassPlus::ViewAcct()const
{
	Formatting f = setformat();
	cout << "BrassPlus Client: " << fullname() << endl;
	cout << "Account Number: " << Acctnum() << endl;
	cout << "Balance : $" << Balance() << endl;
	cout << "Maximum loan:$" << maxLoan << endl;
	cout << "Owed to Bank:$" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << "%\n";
	restore(f);

}
void BrassPlus::Withdraw(double amt)
{
	Formatting f = setformat();
	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt < bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance: $" << advance << endl;//透支
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	restore(f);

}