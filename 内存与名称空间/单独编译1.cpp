# include <iostream>
# include "coordin.h"
using namespace std;
int main1()
{
	rect rplace;//����ͷ�ļ��нṹ����
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers(q to quit): ";//q��cin >> rplace.x >> rplace.y���Ͳ�ƥ�������˳�

	}
	cout << "Bye!\n";
//����������Է�����һ��.c�ļ���


	system("pause");
	return 0;

}