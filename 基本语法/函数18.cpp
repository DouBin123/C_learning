# include <iostream>
using namespace std;
//*********C++�ķ���ֵ����Ϊ���飬�������ǽṹ�Ͷ�����˿��Խ�������Ϊ�ṹ����������������
//��ָ�������б�ʱӦ����...
//ʵ�Σ�argument,�βΣ�parameter
/*
���������õı�д��ʽ��
�������޸����飺void fun(const double x[]);//a[]=*a��ָ��a��ָ��
���������޸����飺void fun(double *x);
ָ���������䣺void fun(int* begin,int*end);//����ʱ�������������ַ
const int *pt=&a; int *pt=&a;//����ͨ��pt��p����a��ֵ��������ͨ��p�޸�a������p��ֵ���޸�
int  *const pm,��pm��ֵҲ�޷��޸�
��ֹ��const������constָ�룬����ǿ��ת��
*/
//************************�������ά����*****************
/*
arr=&arr[0],&arr=����������׵�ַ��arr[k]=*(arr+k),k<n;
int data[3][4]=����1,2,3,4������4,5,6,7������7,8,9,0����;
int (*data)[4]=int data[][4];//����һ������ָ�룬dataָ��int [4]������
//int *data[4];//����һ��ָ�����飬4��Ԫ��Ϊָ��int ��ָ��
dataָ�����飨����Ԫ����4��int��ɵ����飩�ĵ�һ��Ԫ�أ����data[r]ָ����Ϊr��Ԫ�أ���Ԫ��Ϊһ�����飬��data[r]Ҳ����4��intԪ����ɵ����������
data[r][c]����4��int��ɵ�����ĵ�һ��Ԫ�أ�data[r][c]=*��*��data+r��+c����*��data+r��=data[r]
data[1]=*(data+1)=��4,5,6,7��=arr[4]
data[1][3]=*(data[1]+3)=*(arr+3)=7
*/
unsigned int c_in_str(const char *str, char ch);//��������
int main18()
{
	char mmm[15] = "minimum";
	char *wail = "ululate";//wail point to string
	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << ms << " m characters in " << mmm << endl;
	cout << us << " u characters in " << wail << endl;


	system("pause");
	return 0;
}
unsigned int c_in_str(const char* str, char ch)
{
	unsigned int count = 0;

	while (*str)//quit when *str is '\0'
	{
		if (*str == ch)
			count++;
		str++;//move pointer to next char
	}
	return count;
}