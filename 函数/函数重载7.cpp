# include <iostream>
using namespace std;
unsigned long left(unsigned long num, unsigned ct);
char *left(const char *str, int n = 1);
//������̬�����أ��������ʹ�ö��ͬ�������������ͬ���ܣ�ʹ�ò�ͬ����
//�������Ϳ��Բ�ͬ���������꣨���������벻ͬ
//��const ���Ը���const������֮����
//ͬһ��Ŀ�в��ܶ�����ͬ�ĺ���
/*
��ֵָ���ܹ������ڵȺ���ߣ�Ҳ�ܳ����ڵȺ��ұߵı�������ֵ����ֻ�ܳ����ڵȺ��ұߵı���
��ֵ�ǿ�Ѱַ�ı������г־��ԣ�
��ֵһ���ǲ���Ѱַ�ĳ��������ڱ��ʽ��ֵ�����д�����������ʱ���󣬶����Եġ�

int x = 6; // x����ֵ��6����ֵ
int &y = x; // ��ֵ���ã�y����x

int &z1 = x * 6; // ����x*6��һ����ֵ
const int &z2 =  x * 6; // ��ȷ�����Խ�һ��const���ð󶨵�һ����ֵ

int &&z3 = x * 6; // ��ȷ����ֵ����
int &&z4 = x; // ����x��һ����ֵ
*/
int main7()
{
	char *trip = "Hawaii";
	unsigned long n = 12345678;
	int i;
	char *temp;
	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}


	system("pause");
	return 0;
}
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;//ͳ������λ��
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;//�ɵ�λ���λ���
		return num;
	}
	else
		return num;//Ҫ���ȡ��λ�����ڸ���������λ��ʱ�����ԭ����

}
char * left(const char  *str, int n)//��ȡ�ַ���
{
	if (n < 0)
		n = 0;
	char*p = new char[n + 1];
		int i;
		for (i = 0; i < n&&str[i]; i++)
			p[i] = str[i];
		while (i <= n)
		{
			p[i++] = '\0';
		}
		return p;

}