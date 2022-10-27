# include <iostream>
# include "coordin.h"
using namespace std;
int main1()
{
	rect rplace;//引用头文件中结构声明
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers(q to quit): ";//q与cin >> rplace.x >> rplace.y类型不匹配所以退出

	}
	cout << "Bye!\n";
//函数定义可以放在另一个.c文件中


	system("pause");
	return 0;

}