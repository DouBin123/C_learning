//# include <iostream>
//# include"brass.h"
//using namespace std;
//
////formatting stuff declaration
//typedef ios_base::fmtflags format;
//typedef streamsize precis;
//format setFormat();
//void restore(format f, precis p);
//
////brass method
//Brass::Brass(const string &s, long an, double bal)
//{
//	fullName = s;
//	acctNum = an;
//	balance = bal;
//
//}
//void Brass::Deposit(double amt)
//{
//	if (amt < 0)
//		cout << "Neqative deposit not allowed; "
//		<< "deposit is cancelled.\n";
//	else
//		balance += amt;//结余
//}
//void Brass::Withdraw(double amt)
//{
//	//set up ###.## format
//	format initialstate = setFormat();
//	precis prec = cout.precision(2);
//	if (amt < 0)
//		cout << "Withdraw amount must be positive;"
//		<< "withdraw cancelled.\n";
//	else if (amt <= balance)
//		balance -= amt;
//	else//取的大于余额
//		cout << "Withdraw amount of $" << amt
//		<< " exceeds your balance.\n"
//		<< "Withdraw cancelled.\n ";
//	restore(initialstate, prec);//格式恢复
//}
//double Brass::Balance()const
//{
//	return balance;
//}
//void Brass::ViewAcct()const
//{
//	//set up ###.## format
//	format initialstate = setFormat();
//	precis prec = cout.precision(2);
//	cout << "Client: " << fullName << endl;
//	cout << "Acount Number: " << acctNum << endl;
//	cout << "Balance: " << balance << endl;
//	restore(initialstate, prec);
//
//}
//
//
////BrassPlus method
//BrassPlus::BrassPlus(const string &s, long an, double bal,
//	double m1, double r) :Brass(s, an, bal)
//{
//	maxLoan = m1;
//	owesBank = 0.0;
//	rate = r;
//
//}
//void BrassPlus::ViewAcct()const
//{
//	//set up ###.## format 
//	format initialstate = setFormat();
//	precis prec = cout.precision(2);
//
//	Brass::ViewAcct();
//	cout << "Maximum loan: $" << maxLoan << endl;
//	cout << "Owed to bank: $" << owesBank << endl;
//	cout.precision(3);
//	cout << "Loan Rate: " << 100 * rate << "%\n";
//	restore(initialstate, prec);
//}
//void BrassPlus::Withdraw(double amt)
//{
//	//formatting setting ##.##
//	format initialstate = setFormat();
//	precis prec = cout.precision(2);
//
//	double bal = Balance();
//	if (amt <= bal)
//		Brass::Withdraw(amt);
//	else if (amt < bal + maxLoan - owesBank)
//	{
//		double advance = amt - bal;
//		owesBank += advance*(1.0 + rate);
//		cout << "Bank advance: $" << advance << endl;//透支
//		cout << "Finance charge: $" << advance*rate << endl;
//		Deposit(advance);
//		Brass::Withdraw(amt);
//	}
//	else
//		cout << "Credit limit exceeded. Transaction cancelled.\n";
//	restore(initialstate, prec);
//}
//format setFormat()
//{
//	return cout.setf(ios_base::fixed, ios_base::floatfield);
//
//}
//void restore(format f, precis p)
//{
//	cout.setf(f, ios_base::floatfield);//定点输出，小数点后6位
//	cout.precision(p);
//
//}
