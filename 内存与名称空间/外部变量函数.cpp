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
	//������ȫ�ֱ���ͬ���ľֲ�����֮�󣬾ֲ�����������ȫ�ֱ���
	cout << "Local warming = " << warming << " degrees.\n";
	cout << "But global warming = " << ::warming;
	//::��ʾʹ�ñ�����ȫ�ְ汾
	cout << " degrees'\n";
//ʹ��const��ֹ���ݱ��޸�
	const char * const month[12] =//����ָ������
		//��һ��const��ֹ�ַ������޸ģ��ڶ���const ȷ��������ÿ��ָ��ָ�������ָ���λ��
	{"January","February","March","April","May",
	"June","July","August","September","October","November","December"};
}