//ֱ������ϵת��Ϊ������ϵ
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
	while (cin >> rplace.x >> rplace.y)//����cinʱ������һ��istream����cin��istream��һ��������ˣ���ε��ó�ȡ�����>>�õ�������istreamֵ���ж������Ƿ�������ͷ���true/false
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers(q to quit): ";//'q'����double 
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
	const double Rad_to_deg = 57.29577951;//����ת�Ƕ�
	cout << "distance= " << dapos.diatance;
	cout << ", angle= " << dapos.angle*Rad_to_deg;
	cout << "degrees\n";

}