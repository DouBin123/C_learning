# include <iostream>
using namespace std;
//various notation,same signatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int );
const double * f3(const double *, int );
//ֻ���ú���f1(const double ar[], int n)���򷵻ص���double ����ֵ�ĵ�ַ
typedef const double *(*p_fun)(const double *, int);//����һ������
int main25()
{
	double av[] = { 1112.3, 1542.6, 2227.9 };
	cout << &av[0] << endl;
	const double * (*p1)(const double *��int);
	auto p2 = f2;
	p_fun p3 = f3;//���͵Ķ���ʹ�ó����������Լ���
	cout << "Using pointer to functions:\n";
	cout << "Address Value\n";
	cout << f1(av, 3) << ": " << *f1(av, 3)<< endl;
	const double * (*pa[3])(const double *, int) = { f1, f2, f3 };
	//auto ��������һ�����еĳ�ʼ�������������ڵ�ֵ�ĳ�ʼ��
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
	auto pc = &pa;//pcΪ������˫ָ��
	//const double *(*��*pc��[3])(const double*, int) = & pa;
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	//(*pc)[0](av, 3)Ϊav ��doubleֵ�ĵ�ַ
	const double *(*(*pd)[3])(const double*, int) = &pa;
	//(*pd)[3]:pd�洢һά�����׵�ַ
	const double *pdb = (*pd)[1](av,3);//��ȡ�׵�ַΪpa,Ȼ�����ƫ��
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