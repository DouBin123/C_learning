//#ifndef BRASS_H_
//#define BRASS_H_
//
//#include<string>
////Brass Acount Class
//class Brass
//{
//private:
//	std::string fullName;
//	long acctNum;
//	double balance;
//public:
//	Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
//	void Deposit(double amt);
//	double Balance()const;
//	virtual void Withdraw(double amt);//虚方法
//	virtual void ViewAcct()const;
//	virtual ~Brass(){}
//};
//
////虚析构函数的指针指向Brass对象，调用时只针对Brass对象
////Brass Plus Acount Class
//class BrassPlus :public Brass
//{
//private:
//	double maxLoan;
//	double rate;
//	double owesBank;
//public:
//	BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
//	BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
//	virtual void ViewAcct()const;
//	virtual void Withdraw(double amt);
//	void ResetMax(double m){ maxLoan = m; }
//	void ResetRate(double r){ rate = r; }
//	void ResetOwes(){ owesBank = 0; }
//};
//
//#endif