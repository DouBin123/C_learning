# include <iostream>
# include <cstdlib>//rand(),srand()
# include <ctime>//time()
# include "vector.h"
int main2()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));//time(0)返回当前时间，srand()会覆盖之前的种子
	double direction;
	Vector step;
	Vector result(0.0, 0.0);//初始化为RECT
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance(q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		while (result.magval() < target)//使走过的路程为目标路程
		{
			direction = rand() % 360;//返回0-359的随机数
			step.reset(dstep, direction, Vector::POL);//只是判断在POL时x,y的转换与赋值，没有返回值，所以result的Mode没有改变
			result =result+ step;//假发运算符创建并返回一个新矢量，该函数使用默认构造函数以RECT模式创建矢量
			steps++;//记录走的步数
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n " << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target diatance(q to quit): ";
	}
	cout << "Bye!/n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	system("pause");
	return 0;


}