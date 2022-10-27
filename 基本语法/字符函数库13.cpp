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
		if (isalpha(ch))//是字母
			chars++;
		else if (isspace(ch))//是标准空白符
			whitescape++;
		else if (isdigit(ch))//是数字
			digits++;
		else if (ispunct(ch))//是标点
			punct++;
		else
			others++;
		cin.get(ch);//得到下一个字符
	}
	cout << chars << "letters, "
		<< digits << "digits, "
		<< punct << "punctuations, "
		<< others << "others.\n";
//***************“？:”***********
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
isalnum():是字母或数字
iscntrl():是控制字符
isgragh():是除空格外的打印字符
islower():是小写
isprint():是打印字符
isupper():是大写
isxdigit():是十六进制
tolower():若是大写，则返回小写，否则返回参数
toupper():若是小写，则返回大写，否则返回参数
*/


	system("pause");
	return 0;

}