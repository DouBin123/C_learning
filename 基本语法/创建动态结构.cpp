# include <iostream>
struct inflable
{
	char name[20];
	float volume;
	double price;
};
int main7()
{
	using namespace std;
	inflable *ps = new inflable;//����һ�����ڴ洢�ṹ����ڴ沢�����׵�ַ
	cout << "Enter name of inflable item:  ";
	cin.get(ps->name, 20);//���ʽṹ���Ա�ķ���һ
	cout << "Enter volume in cubic feet:  ";
	cin >> (*ps).volume;//���ʽṹ���Ա�ķ���������*ps��=�ṹ����
	cout << "Enter price:$";
	cin >> ps->price;
	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << " cubic feet \n";
	cout << "Price :$" << ps->price << endl;
	delete ps;
	system("pause");
	return 0;
}