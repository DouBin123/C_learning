# include <iostream>
using namespace std;
const int ArSize = 80;
char *left1(const char * str, int n = 1);//ֻ�ܴ�����������Ĭ�ϲ������ڵ��ú���ʱ����ʡ�Ըò���
int main6()
{
	char sample[ArSize];
	cout << "Enter a string: \n";
	cin.get(sample, ArSize);
	char *ps = left1(sample, 4);//��������ֵΪָ�룬����ƥ��
	cout << ps << endl;
	delete[] ps;//�ͷ��ڴ�,��Ϊ�ں�������ʱʹ����new char[]
	ps = left1(sample);
	cout << ps << endl;
	delete[] ps;


	system("pause");
	return 0;
}
char *left1(const char *str, int n)
{
	if (n < 0)
	{
		n = 0;
	}
	char *p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++)
	{
		p[i] = str[i];
	}//��������i,��ȡ��n���ǿ��ַ�֮���ں��渳��\0��
	while (i <= n)
			p[i++] = '\0';
	return p;

}