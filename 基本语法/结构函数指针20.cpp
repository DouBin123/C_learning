//直角坐标系转换为极坐标系
# include <iostream>
# include <cmath>
using namespace std;
struct polar
{
	double diatance;
	double angle;
};
struct rect
{
	double x;
	double y;

};
void rect_to_polar(const rect *pxy,polar *pda);//没有返回值，直接在参数中定义可修改的变量
void show_polar(const polar  *pda);
int main20()
{
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)//调用cin时将返回一个istream对象，cin是istream的一个对象，因此，多次调用抽取运算符>>得到的仍是istream值，判断输入是否符合类型返回true/false
	{
		rect_to_polar(&rplace,&pplace);
		show_polar(&pplace);
		cout << "Next two numbers(q to quit): ";//'q'不是double 
	}
	cout << "Done.\n";
	system("pause");
	return 0;
}
void rect_to_polar(const rect *pxy,polar *pda)
{
	pda->diatance = sqrt(pxy->x*pxy->x + pxy->y*pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}
void show_polar(const polar *pda)
{
	const double Rad_to_deg = 57.29577951;//弧度转角度
	cout << "distance= " << pda->diatance;
	cout << ", angle= " << pda->angle*Rad_to_deg;
	cout << "degrees\n";

}