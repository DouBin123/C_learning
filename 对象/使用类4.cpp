# include <iostream>
# include "stock00.h"
int main4()
{
	{
		using std::cout;
		cout << "Using constructors to create new objects\n";
		Stock stock1("NanoSmart", 12, 20.0);//syntax,��ʽ��������
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);//syntax,��ʽ�������󣬻������ʱ���󣬲���ֵ����stock2�������ù�������
		stock2.show();//Stock������Ϊ��ʼ��

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;
		cout << "Listening stock1 and stock2:\n";
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);//�������ʱ���󣬲���ֵ����stock1�������ù���������Stock����Ϊ��ֵ�����ǳ�ʼ��
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done\n";

	
	
	}//�ô��������˶�����������ڣ����û�У�������Ϊ����main������ֻ����ִ��������ʱ�Ż�ִ�й�������
	system("pause");
	return 0;


}