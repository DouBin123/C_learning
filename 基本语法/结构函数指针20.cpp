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
void rect_to_polar(const rect *pxy,polar *pda);//û�з���ֵ��ֱ���ڲ����ж�����޸ĵı���
void show_polar(const polar  *pda);
int main20()
{
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)//����cinʱ������һ��istream����cin��istream��һ��������ˣ���ε��ó�ȡ�����>>�õ�������istreamֵ���ж������Ƿ�������ͷ���true/false
	{
		rect_to_polar(&rplace,&pplace);
		show_polar(&pplace);
		cout << "Next two numbers(q to quit): ";//'q'����double 
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
	const double Rad_to_deg = 57.29577951;//����ת�Ƕ�
	cout << "distance= " << pda->diatance;
	cout << ", angle= " << pda->angle*Rad_to_deg;
	cout << "degrees\n";

}