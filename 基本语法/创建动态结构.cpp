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
	inflable *ps = new inflable;//申请一块用于存储结构体的内存并返回首地址
	cout << "Enter name of inflable item:  ";
	cin.get(ps->name, 20);//访问结构体成员的方法一
	cout << "Enter volume in cubic feet:  ";
	cin >> (*ps).volume;//访问结构体成员的方法二，（*ps）=结构体名
	cout << "Enter price:$";
	cin >> ps->price;
	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << " cubic feet \n";
	cout << "Price :$" << ps->price << endl;
	delete ps;
	system("pause");
	return 0;
}