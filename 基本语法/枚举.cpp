# include <iostream>
using namespace std;
int main4()
{
	enum spectrum{red,orange,yellow};//��Ӧ0-2
	spectrum brand;//ʵ��������
	brand = red;//ֻ�и�ֵ���㣬������������
	enum bigstep{ first,second=100,third};//0,100,101
	enum { zero, null, one, num = 1};//0,0,1,1
	bigstep a = bigstep(50);//�ڷ�Χ�ڣ��Ϸ�
	cout << a << endl;
	cout << red << endl;
	cout << third << endl;




	system("pause");
	return 0;
}