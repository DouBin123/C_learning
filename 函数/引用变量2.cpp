# include <iostream>
using namespace std;
//��������������ֵ��ζ��ֵ���ݽ�������
#pragma region not_fun
void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);//������
double cube(double a);
double refcube(double &ra);//�����ô��ݻ�ı�ʵ�ε�ֵ
#pragma endregion
//�����õĶ�����const�������Ͳ���ȷ������ֵʱ����������ʱ����
/*
Ӧ������ʹ��const����
1��ʹ��const���Ա����������޸����ݵı�̴���
2��ʹ��const ʹ�����ܹ�����const�ͷ�constʵ�Σ�����ֻ���ܷ�const����
3��ʹ��const����ʹ�����ܹ���ȷ���ɲ�ʹ����ʱ����
*/
//C++11��������ֵ����
double &&reff = sqrt(36.0);
int main2()
{
	//��*�����һ�����ڶ������������ʱ��&��ʾ���ñ�������ʾ������������ͬһ��ַ��ֵ
#pragma region MyRegion
int rats = 101;
	int &rodents = rats;
	cout << "rats= " << rats << endl;
	cout << ",rodents= " << rodents << endl;
	rodents++;
	cout << "rats= " << rats << endl;
	cout << ",rodents= " << rodents << endl;
	cout << "address rats= " << &rats << endl;
	cout << ",address rodents= " << &rodents << endl;
	int bunnies = 50;
	rodents = bunnies;//������ԭ������ֵ���ˣ�����ַδ��
	cout << "bunnies= " << bunnies << endl;
	cout << "rats= " << rats << endl;
	cout << ",rodents= " << rodents << endl;
	cout << "address bunnies= " << &bunnies << endl;
	cout << "address rats= " << &rats << endl;
	cout << "address rodents= " << &rodents << endl;
	
#pragma endregion
#pragma region swap

	int wallet1 = 300;
	int wallet2 = 320;
	cout << "wallet1=$ "<<wallet1;
	cout << "wallet2=$ " << wallet2<<endl;
	cout << "Using references to swap contents:\n";
	swapr(wallet1, wallet2);
	cout << "wallet1=$ " << wallet1;
	cout << "wallet2=$ " << wallet2 << endl;
	cout << "Using references to swap contents agin:\n";
	swapp(&wallet1, &wallet2);
	cout << "wallet1=$ " << wallet1;
	cout << "wallet2=$ " << wallet2 << endl;
	cout << "Trying to use passing by value:\n";
	swapv(wallet1, wallet2);
	cout << "wallet1=$ " << wallet1;
	cout << "wallet2=$ " << wallet2 << endl;

#pragma endregion
#pragma region cube
	double x = 3.0;
	cout << cube(x);
	cout << "= cube of " << x << endl;
	cout << refcube(x);
	cout << "= cube of " << x << endl;

#pragma endregion
	system("pause");
	return 0;

}
void swapr(int &a, int &b)//�����ô���
{
	int temp=a;
	a = b;
	b = temp;
}
void swapp(int *p, int *q)//����ַ����
{
	int temp = *p;
	*p = *q;
	*q = temp;

}
void swapv(int a, int b)//��ֵ���ݣ��൱�ڸ�����ԭʵ�ε�ֵ
{
	int temp = a;
	a = b;
	b = temp;

}
double cube(double a)
{
	a *= a*a;
	return a;
}
double refcube(double &ra)
{
	ra *= ra*ra;
	return ra;
}