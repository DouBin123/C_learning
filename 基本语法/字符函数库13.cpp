# include <iostream>
# include <cctype>
using namespace std;
int main13()
{
	cout << "Enter text for analysis,and type @"
		"to terminate input.\n";
	char ch;
	int whitescape = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;
	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))//����ĸ
			chars++;
		else if (isspace(ch))//�Ǳ�׼�հ׷�
			whitescape++;
		else if (isdigit(ch))//������
			digits++;
		else if (ispunct(ch))//�Ǳ��
			punct++;
		else
			others++;
		cin.get(ch);//�õ���һ���ַ�
	}
	cout << chars << "letters, "
		<< digits << "digits, "
		<< punct << "punctuations, "
		<< others << "others.\n";
//***************����:��***********
	const char x[2][20] = { "Jason ", " at your service\n" };
	const char *y = " Quillstone ";
	for (int i = 0; i < 3; i++)
	{
		cout << ((i < 2) ? !i ? x[i] : y : x[1]);
	}
	/*
	i=0,(i<2)?x[0]:x[1]--->x[0]
	i=1,(i<2)?y:x[1]--->y
	i=0,(i<2)?y:x[1]--->x[1]
	*/
	
/*
isalnum():����ĸ������
iscntrl():�ǿ����ַ�
isgragh():�ǳ��ո���Ĵ�ӡ�ַ�
islower():��Сд
isprint():�Ǵ�ӡ�ַ�
isupper():�Ǵ�д
isxdigit():��ʮ������
tolower():���Ǵ�д���򷵻�Сд�����򷵻ز���
toupper():����Сд���򷵻ش�д�����򷵻ز���
*/


	system("pause");
	return 0;

}