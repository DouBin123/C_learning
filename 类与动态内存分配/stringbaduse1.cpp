# include <iostream>
# include "String1.h"
using  std::cout;

void callme1(String1 &);//pass by reference
void callme2(String1);

int main1()
{
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		String1 headingline1("Celery Stalks at Midnight");
		String1 headingline2("Lettuce Prey");
		String1 sports("Spinach Leaves Bowl for Dollars");

		cout << "headline1: " << headingline1 << endl;
		cout << "headline2: " << headingline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headingline1);
		cout << "headline1: " << headingline1 << endl;
		callme2(headingline2);//��ֵ���ö���������ʱ���󣬵��ø��ƹ��캯���������������������ã�Դ�ַ����޷�ʶ��
		cout << "headline2: " << headingline2 << endl;
		cout << "Initialize one object to another:\n";
		
		String1 sailor = sports;//ʹ�ø��ƹ��캯��
		//String1(const SringBad &);ʹ��һ����������ʼ����һ������ʱ���Զ�����
		cout << "sailor: " << sailor << endl;
		cout << "Assign one object to another:\n";
		String1 knot;
		knot = headingline1;//ʹ�ø�ֵ����������Ƶ��ǵ�ַ�����ַ�����ԭ���������������ʱ����ַ��Ч
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	}
	system("pause");
	return 0;
}

void callme1(String1 & rsb)
{
	cout << "String passed by reference:\n";
	cout << "   \"" << rsb << "\"\n";

}
void callme2(String1 sb)
{
	cout << "String passed by value:\n";
	cout << "  \"" << sb << "\"\n";

}