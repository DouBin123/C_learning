# include <iostream>
# include <cstdlib>//rand(),srand()
# include <ctime>//time()
# include "vector.h"
int main2()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));//time(0)���ص�ǰʱ�䣬srand()�Ḳ��֮ǰ������
	double direction;
	Vector step;
	Vector result(0.0, 0.0);//��ʼ��ΪRECT
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance(q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		while (result.magval() < target)//ʹ�߹���·��ΪĿ��·��
		{
			direction = rand() % 360;//����0-359�������
			step.reset(dstep, direction, Vector::POL);//ֻ���ж���POLʱx,y��ת���븳ֵ��û�з���ֵ������result��Modeû�иı�
			result =result+ step;//�ٷ����������������һ����ʸ�����ú���ʹ��Ĭ�Ϲ��캯����RECTģʽ����ʸ��
			steps++;//��¼�ߵĲ���
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