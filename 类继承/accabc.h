# ifndef ACCTABC_H_
# define ACCTABC_H_
# include <iostream>
# include<string>

class AcctABC
{
private:
	std::string FullName;//函数与变量最好不要同名
	long acctnum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;

	};
	const std::string &fullname()const{ return FullName; };//只读保护
	long Acctnum()const{ return acctnum; };
	Formatting setformat()const;
	void restore(Formatting &f)const;

public:
	AcctABC(const std::string &s = "nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;//pure virtual function
	double Balance()const { return balance; }
	virtual void ViewAcct()const = 0;
	virtual ~AcctABC(){};

};
class Brass:public AcctABC
{
public:
	Brass(const std::string &s = "nullbody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal){}
	virtual void Withdraw(double amt);
	virtual void ViewAcct()const;
	virtual ~Brass(){};//声明了必须有函数体
};
class BrassPlus :public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string &s="nullbody", long an=-1, double bal=0.0,double ml=500, double r=0.10);
	BrassPlus (const Brass &ba,double ml=500,double r=0.10);//这里两个类的关系有限定吗/没有
	virtual void ViewAcct()const;
	virtual void Withdraw(double amt);
	void ResetMax(double m){ maxLoan = m; };
	void ResetRate(double r){ rate = r; };
	void ResetOwes(){ owesBank = 0; }
	
};


#endif