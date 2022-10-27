# include <iostream>
using namespace std;
//ģ�嶨��
/*
template <class AnyType>
void Swap(AnyType &a, AnyType &b)
{
	AnyType temp;
	temp = a;
	a = b;
	b = temp;

}
*/
/*
��������ѡ�����ӣ�
1����ȫƥ�䣬�����溯��������ģ��
2������ת����char/short-->int ,floatת��Ϊdouble���䳤
3����׼ת����int--char��long---double��
4���Զ���ת��
*/
template <typename T>//or class T
void Swap(T &a, T &b);

template<typename T>//overload template
void Swap(T *a, T *b, int n);

void Show(int a[]);

const int Lim = 8;
//��ʽ���廯
struct job//�������彻����ֵ
{
	char name[40];
	double salary;
	int floor;

};
template<>void Swap(job &j1, job &j2);//���廯-----��ʽʵ����
void Show(job &j);//��������
template <class T>//�Զ���ѡ��
T lesser(T a, T b)
{
	return a < b ? a : b;

}

int lesser(int a, int b)
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return  a < b ? a : b;
}

template <class T1,class T2>
void ft(T1 x, T2 y)
{
	decltype(x + y) z = x + y;//��֪x��y���ͣ�z��(x+y)����һ��

}

template <class T1, class T2>
auto gt(T1 x, T2 y)->decltype(x + y)
{
	return x + y;

}

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	//��һ������ָ��Ҫ������Щλ���ڶ�������ָ��Ҫ�����Щλ��
	int i = 10;
	int j = 20;
	cout << "i,j= " << i << "," << j << endl;
	cout << "Using compiler generated int swapper:\n";
	Swap(i, j);
	cout << "Now i,j= " << i << "��" << j << endl;

	double x = 24.5;
	double y = 81.7;
	cout << "x,y= " << x<< "," << y << endl;
	cout << "Using compiler generated int swapper:\n";
	Swap(x, y);//���廯-----��ʽʵ����
	cout << "Now x,y= " << x << "��" << y << endl;
	int d1[Lim] = { 0, 7, 0, 4, 1, 7, 7, 6 };
	int d2[Lim] = { 0, 7, 2, 0, 1, 9, 6, 9 };
	cout << "Oriiginal arrays:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "Swapped arrays:\n";
	Show(d1);
	Show(d2);
# pragma region special
	job sue = { "Sidny Yaffee", 73000.60, 7 };
	job sidney = { "Sidny Yaffee", 70806.72, 9 };
	cout << "Before job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "After job swapping:\n";
	Show(sue);
	Show(sidney);

#pragma endregion
#pragma region choice
	int m = 20;
	int n = -30;
	double x1 = 15.5;
	double y1 = 25.9;

	cout << lesser(m, n) << endl;//��ģ��
	cout << lesser(x1, y1) << endl;//ģ��
	cout << lesser<>(m, n) << endl;//ģ��
	cout << lesser<int>(x1, y1) << endl;//ģ��---��ʽʵ����
#pragma endregion
#pragma region	lambda
	//lambda�������ʽ��������������auto ������=[capture](parameters)->return-type{body}
	//ֱ��ͨ������������
	//[����Ӿ�]���β��б�-> ����˵�������������ָ����������
	//[����Ӿ�]���β��б�)���������δָ���������ͣ��Զ�ʶ��
	/*
	[]      // �]�ж����κα�����ʹ��δ�����������������
	[x, &y] // x�Դ�ֵ��ʽ���루Ĭ�ϣ���y�����÷�ʽ���롣
	[&]     // �κα�ʹ�õ����ⲿ��������ʽ�������÷�ʽ�������á�
	[=]     // �κα�ʹ�õ����ⲿ��������ʽ���Դ�ֵ��ʽ�������á�
	[&, x]  // x��ʽ���Դ�ֵ��ʽ�������á�������������÷�ʽ�������á�
	[=, &z] // z��ʽ�������÷�ʽ�������á���������Դ�ֵ��ʽ�������á�
	[this]��ͨ�����ò���ǰ������ʵ�Ǹ���ָ�룩��
	[*this]��ͨ����ֵ��ʽ����ǰ����

	*/
	//lambda���ʽ�޷��޸�ͨ��������ʽ��׽�ı�������Ϊ������������������ط�����const���Եġ�
	//��෵��ֵ���������Ҳ���ִ�еĹ��ܣ���������
	//�޲������޷���ֵ��

	auto m1 = [](){ cout << "Hello World" << endl; };
	getchar();
	m1;
	int x2 = 10;
	auto add_x = [x2](int a) mutable { x2 *= 2; return a + x2; };  // ���Ʋ�׽x
	std::cout << add_x(10) << endl; // ��� 30


#pragma endregion
	

    system("pause");
	return 0;
}
template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;

}
template <typename T>
void Swap(T a[], T b[],int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
	temp = a[i];
	a[i] = b[i];
	b[i] = temp;
	}	
}
void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
		cout << endl;

}
//ģ��ľ�����:�������ͱ������ϵ����㣬����������帳ֵ���ṹ�������帳ֵ�����ṹ�ıȽϵȵ�
template<>void Swap<job>(job &j1, job &j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}
void Show(job &j)
{
	cout << j.name << ": $" << j.salary
		<< "on floor " << j.floor << endl;

}
/*
��־	����
boolalpha	����ʹ�õ���"true"��"false"��������/����Ĳ���ֵ.
oct	�ð˽��Ƹ�ʽ��ʾ��ֵ.
dec	��ʮ���Ƹ�ʽ��ʾ��ֵ.
hex	��ʮ�����Ƹ�ʽ��ʾ��ֵ.
left	�������Ϊ�����.
right	�������Ϊ�Ҷ���.
scientific	�ÿ�ѧ��������ʾ������.
fixed	�������ļ���������ʾ������(���ѧ���������Ӧ).
showbase	���ʱ��ʾ������ֵ�Ļ���.
showpoint	��ʾС����Ͷ�����㣬��ʹ����Ҫ.
showpos	�ڷǸ���ֵǰ����ʾ"�������ţ�".
skipws	����һ�������ж�ȡʱ�������հ��ַ�(spaces, tabs, newlines).
unitbuf	��ÿ�β����Ժ���ջ�����.
internal	������ַ��ص����ź���ֵ֮��.
uppercase	�Դ�д����ʽ��ʾ��ѧ�������е�"e"��ʮ�����Ƹ�ʽ��"x".


*/