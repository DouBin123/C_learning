# include <iostream>
extern double warming;
void update(double dt);
void local();

using std::cout;
void update(double dt)
{
	extern double warming;
	warming += dt;
	cout << "Updating global warming to " << warming;
	cout << " degrees.\n";
}
void local()
{
	double warming = 0.8;//new variable hides external one
	//定义与全局变量同名的局部变量之后，局部变量将隐藏全局变量
	cout << "Local warming = " << warming << " degrees.\n";
	cout << "But global warming = " << ::warming;
	//::表示使用变量的全局版本
	cout << " degrees'\n";
//使用const防止数据被修改
	const char * const month[12] =//定义指针数组
		//第一个const防止字符串被修改，第二个const 确保数组中每个指针指向它最初指向的位置
	{"January","February","March","April","May",
	"June","July","August","September","October","November","December"};
}