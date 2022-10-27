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
polar rect_to_polar(rect xypos);
void show_polar(polar  dapos);
int main19()
{
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)//调用cin时将返回一个istream对象，cin是istream的一个对象，因此，多次调用抽取运算符>>得到的仍是istream值，判断输入是否符合类型返回true/false
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers(q to quit): ";//'q'不是double 
	}
	cout << "Done.\n";
	system("pause");
	return 0;
}
polar rect_to_polar(rect xypos)
{
	polar answer;
	answer.diatance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}
void show_polar(polar dapos)
{
	const double Rad_to_deg = 57.29577951;//弧度转角度
	cout << "distance= " << dapos.diatance;
	cout << ", angle= " << dapos.angle*Rad_to_deg;
	cout << "degrees\n";

}