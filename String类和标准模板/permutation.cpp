/*
｛1,2，3｝第一位有n种可能性，确定了第一位就是求后面剩下n-1的数据的全排列问题
f(1,2,3)={第一位是1,f(n-1)}+{第一位是2,f(n-1)}+{第一位是3,f(n-1)}
也就是将第一位与第n（0,1,2……)位依次交换
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
	//基准点
	if (*pPosition == '\0')
		cout << pStr << endl;
	else
	{
		for (char*pChar = pPosition; *pChar != '\0'; pChar++)
		{//依次和后面字符交换
			swap(*pChar, *pPosition);//pPosition是当前确定的位置，将*pPosition与*pStr++交换
			cout << pStr << " ";
			permutation(pStr, pPosition + 1);//确定下一个位置，最后加递归
			//换回来
			swap(*pChar, *pPosition);//保证原数字顺序不变才能交换所有的数据
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