# include <iostream>
const  int Arsize = 10;//�����޸�ȫ�ֱ���
void strcount(const char* str);
int main4()
{


	using namespace std;
	char input[Arsize];
	char next;

	cout << "Enter a line:\n";
	cin.get(input, Arsize);//��ȡ�ַ��������հ׷�����Arsize-1��.���Խ��ܿո��ַ�������Enter�������룬���ճ���(Arsize)��ȡ�ַ�, �ᶪ������Enter�ַ�
	while (cin)//get(char*,int)��ȡ���н�����cinΪfalse
	{
		cin.get(next);//��ȡnext,��������Ƿ����
		while (next != '\n')//input������ֹͣ�����������һ����ENTER����һ�����ַ�����ΪArsize-1
			//����ǵ�һ�֣�˵�������������ȡ�س�Ϊnext���ڶ���˵�������������ʣ��һ���洢��next
			cin.get(next);
		strcount(input);
		cout << "Enter next line (empty line quit): \n";
		cin.get(input, Arsize);
	}
	cout << "Bye\n";


	system("pause");
	return 0;

}
void strcount(const char * str)
{
	using namespace std;
	static int  total = 0;//��̬�ֲ�����
	int count = 0;//�ֲ����������ɴ洢������

	cout << "\"" << str << "\"contains ";//ת���ַ�
	while (*str++)
	{
		count++;
	}
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";

}