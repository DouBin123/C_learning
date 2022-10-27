# include <iostream>
using namespace std;
//various notation,same signatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int );
const double * f3(const double *, int );
//只调用函数f1(const double ar[], int n)，则返回的是double 返回值的地址
typedef const double *(*p_fun)(const double *, int);//定义一种类型
int main25()
{
	double av[] = { 1112.3, 1542.6, 2227.9 };
	cout << &av[0] << endl;
	const double * (*p1)(const double *，int);
	auto p2 = f2;
	p_fun p3 = f3;//类型的定义使得程序出错可能性减少
	cout << "Using pointer to functions:\n";
	cout << "Address Value\n";
	cout << f1(av, 3) << ": " << *f1(av, 3)<< endl;
	const double * (*pa[3])(const double *, int) = { f1, f2, f3 };
	//auto 不能用于一个序列的初始化，但可以用于单值的初始化
	auto pb = pa;
	cout << "\nUsing an array of pointer to functions:\n";
	cout << "Adress Value\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pa[i](av, 3) << ":" << *pa[i](av, 3) << endl;
	}
	cout << "\nUsing an array of pointer to functions:\n";
	cout << "Adress Value\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pb[i](av, 3) << ":" << *pb[i](av, 3) << endl;
	}
	cout << "\nUsing an array of pointer to functions:\n";
	cout << "Adress Value\n";
	auto pc = &pa;//pc为函数的双指针
	//const double *(*（*pc）[3])(const double*, int) = & pa;
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	//(*pc)[0](av, 3)为av 中double值的地址
	const double *(*(*pd)[3])(const double*, int) = &pa;
	//(*pd)[3]:pd存储一维数组首地址
	const double *pdb = (*pd)[1](av,3);//先取首地址为pa,然后向后偏移
	cout << pdb << ": " << *pdb << endl;
	system("pause");
	return 0;

}
const double *f1(const double *ar, int n)
{
	return ar;

}
const double * f2(const double ar[], int n)
{
	return ar + 1;
}
const double *f3(const double ar[], int n)
{
	return ar + 2;

}