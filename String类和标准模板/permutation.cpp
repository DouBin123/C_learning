/*
��1,2��3����һλ��n�ֿ����ԣ�ȷ���˵�һλ���������ʣ��n-1�����ݵ�ȫ��������
f(1,2,3)={��һλ��1,f(n-1)}+{��һλ��2,f(n-1)}+{��һλ��3,f(n-1)}
Ҳ���ǽ���һλ���n��0,1,2����)λ���ν���
*/
# include <iostream>
# include <algorithm>
using namespace std;
void swap(char* a,char *b)
{
	char temp=*a;
	*a = *b;
	*b = temp;
}
void permutation(char*pStr, char*pPosition)
{
	//��׼��
	if (*pPosition == '\0')
		cout << pStr << endl;
	else
	{
		for (char*pChar = pPosition; *pChar != '\0'; pChar++)
		{//���κͺ����ַ�����
			swap(*pChar, *pPosition);//pPosition�ǵ�ǰȷ����λ�ã���*pPosition��*pStr++����
			cout << pStr << " ";
			permutation(pStr, pPosition + 1);//ȷ����һ��λ�ã����ӵݹ�
			//������
			swap(*pChar, *pPosition);//��֤ԭ����˳�򲻱���ܽ������е�����
		}
			
	}


}


int main()
{
	char test[] = "123";
	permutation(test, test);
	cout << endl;

	system("pause");
	return 0;
}