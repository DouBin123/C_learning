# include <iostream>

int main1()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	int year;
	//cin >> year;//����������лس����ᱻgetline()�ɼ���������Ϊ֮��������ǿ���
	(cin >> year).get();//��ͬ�������͵Ľ��֮��
	cout << "Enter your name:\n";
	//cin >> name;//�������������cin.getline(),�س�����ȷ�������Ƿ��������ɾ�����з�
	//cin.get(name,ArSize);
	//cin.get();//get()���Զ�ȡ��һ�ַ�����ʱ�ǻ��з�
	//cin.get(dessert, ArSize);//get(����)�����ᱣ�����з�������ڵڶ�������δ����ʱ����Ϊ�Ѿ����н���
	cin.get(name, ArSize).get();//cin.get(name, ArSize).get()=cin.get(name,ArSize);cin.get();
	cout << "Enter your favourate dessert:\n";
	//cin >> dessert;
	//cin.getline(dessert, ArSize);
	cin.getline(dessert, ArSize).get();
	//��cin.get()��cin.getline()��ȡ����ʱ��������cin.clear()�ָ�����

	//cin.get(name, ArSize)�᷵��һ��cin���������������get(),��cin.getline(name, ArSize).get(dessert, ArSize)Ч��һ��
	cout << "I have some delicious " << dessert;
	cout << "for you," << name << ".\n";//�ڼ�������ʱ�����򽫣�name���룩�ո���Ϊ��һ���ַ�������(�Զ��ӿ�ֵ�ַ�\0)����������ĵ��ʶ���ڶ�������
	system("pause");









	//cin.get();
	//getchar();
	//system("pause");
	return 0;
}