# include <iostream>
double betsy(int);//���������п���ʡ�Ա�ʶ�������ڶ��庯��ʱ����˵����ʶ��
double pam(int);
void estimate(int lines, double(*pf)(int));
using namespace std;
int main24()
{
	//��������������ַ������������Ϊ����ֵ��
	/*
	int * pt (int)//����һ���������䷵��ֵΪint*����
	int ��*p��(int)//����һ������ָ��p��ָ��int fun(int a);
	*/
	int code;
	cout << "How many lines of code do you need ? ";
	cin >> code;
	cout << "Here's Betsy's estimate:\n";
	estimate(code, betsy);
	cout << "Here's Pam's estimate:\n";
	estimate(code, pam);
//���ú���ʱ������*��������ֱ��ʹ�ú�����
	system("pause");
	return 0;
}
void estimate(int lines,double (*pf)(int))
{
	cout << lines << "lines will take ";
	cout << (*pf)(lines) << "hours\n";//���ú���

}
double betsy(int lns)
{
	return 0.05*lns;
}
double pam(int lns)
{
	return 0.03*lns + 0.0004*lns*lns;

}