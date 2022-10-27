# include <iostream>
# include <cmath>
# include <string>
# include "exc_mean.h"
class demo
{
private:
	std::string word;
public:
	demo(const std::string &str)
	{
		word = str;
		std::cout << "demo: " << word << " created\n";
	
	}
	~demo()
	{
		std::cout << "demo: " << word << " destroyed\n";
	
	}
	void show()const
	{
		std::cout << "demo: " << word << " lives!\n";
	}
};


//function prototypes
double hmean1(double, double);
double gmean1(double, double);
double means1(double, double);

int main7()
{
	using namespace std;

	double x, y, z;
	//��������������
	{
		demo d1("found in block in main");
		cout << "Enter two numbers: ";
		while (cin >> x >> y)
		{
			try{  //start of try block
				z = means1(x, y);
				cout << "The mean mean of " << x << " and " << y
					<< " is " << z << endl;
				cout << "Enter next pair: ";
			}//end of try block
			catch (bad_gmean &hg)
			{
				cout << hg.mesg();
				cout << "Value used: " << hg.v1 << ", "
					<< hg.v2 << endl;
				cout << "Sorry, you don't get to play any more.\n";
				break;
			}//end of catch block
			catch (bad_hmen &bg)
			{
				bg.mesg();
				cout << "Try agin.\n";
				continue;
			}
			
		}
		d1.show();
	}//d1���������ڽ���
	cout << "Bye!\n";
	cin.get();
	cin.get();
	return 0;
}
double hmean1(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmen(a,b);
	}
	return 2.0*a*b / (a + b);
}
double gmean1(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a*b);

}
double means1(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");//�ɺ��������Ķ����ں�������ʱ�������ڽ������Զ�������������
	am = (a + b) / 2.0;
	try
	{
		hm = hmean1(a, b);//�����쳣ʱ���ص�try������ַ
		gm = gmean1(a, b);
	}//end of try block
	catch (bad_hmen &bg)
	{
		bg.mesg();
		std::cout << "Caught in means()\n";
		throw;//(���ָ����ת�ᷢ���仯) bad_gmean(a, b);//rethrows the exception��Я������bad_hmen�Ĵ�����ת��Ϣ
	//����תֱ�ӽ���main()�е� catch������ִ���Ӻ�������Ĵ���
	}
	d2.show();//-4,4����ִ��
	return (am + hm + gm)/3.0;
}