# include <iostream>
# include <string>
struct free_throws
{
   std::string name  ;//string name����,δʹ�����ƿռ�
	int made;
	int attempts;
	float percent;
};
void display(const free_throws &ft);//�ṹ��������
void set_pc(free_throws &ft);
free_throws &accumulate(free_throws & target, const free_throws &source);//����ֵΪ�ṹ�����õĺ���
//����Ӧ��Ӧ���ⷵ�غ�����ֹʱ���ٴ��ڵ��ڴ浥Ԫ�����ã�����ʱ����
using namespace std;
int main3()
{
	//initial
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Branch", 19, 13 };
	free_throws three = { "Minnies Branch", 15, 14 };
	free_throws five = { "Whilyy Branch", 18, 14 };
	free_throws four = { "Long  Branch", 17, 13};
	free_throws team = { "Throed Branch", 0, 0 };
	//no initial
	free_throws dup;
	//display(one);
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
	cout << "���Ʋ�ͬ" << endl;
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	dup = accumulate(team, five);
	cout << "display team:"<<endl;
	display(team);
	set_pc(four);
	accumulate(dup, five);
	cout << "display dup after ill-advised assignment:" << endl;
	display(dup);
	system("pause");
	return 0;

}
void display(const free_throws &ft)
{
	using std::cout;
	cout << "Name: " << ft.name << endl;
	cout << "Made: " << ft.made << endl;
	cout << "Attempts: " << ft.attempts << endl;
	cout << "Percent: " << ft.percent << endl;

}
void set_pc(free_throws &ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f*float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;

}
free_throws &accumulate(free_throws & target, const free_throws &source)//����ֵΪ�ṹ��ĺ���
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;

}