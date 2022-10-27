# include<iostream>
using namespace std;
int  change(const int *pt, int n);

int main()
{
	int pop1 = 3243;
	const int pop2 = 3423;

	cout << "pop1,pop2: " << pop1 << ", " << pop2 << endl;
	int a=change(&pop1, -103);
	int b=change(&pop2, -103);
	cout << "a,b,pop1,pop2: " << a << ", " << b << ", " << pop1 << ", " << pop2 << endl;

	system("pause");
	return 0;

}
int  change(const int *pt, int n)
{
	int *pc;
	pc = const_cast<int *>(pt);//在函数中可以修改它的值，但外部值不变
	*pc += n;
	return *pc;
}