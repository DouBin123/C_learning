# include <iostream>
# include <new>
const int BUF = 512;
const int N = 5;
char buffer[BUF];
int main()
{
	using namespace std;
	double *pd1, *pd2;
	int i;
	cout << "Calling new and placement new:\n";
	pd1 = new double[N];//double指针
	pd2 = new (buffer) double[N];//char指针
	//定位new,不需要 delete，每次调用时使用相同内存块，除非指定偏移量
	//常规new，必须要delete才会在堆中找寻相同的内存块
	for (i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0*i;//赋值
	}
	cout << "Memory addresses: \n" << "heap: " << pd1
		<< "Static: " << (void*)buffer << endl;
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << " ; ";
		cout << pd2[i] << " at " << &pd2[i] << " ; ";
	}

	cout << "\nCalling new and placement new a second time:\n";
	double *pd3, *pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];
	for(i = 0; i < N; i++)
	{
		pd4[i] = pd3[i] = 1000 + 40.0*i;
	}

	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << " ; ";
		cout << pd4[i] << " at " << &pd4[i] << " ; ";
	}

	cout << "\nCalling new and placement new a second time:\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer+N*sizeof(double)) double[N];//含偏移量
	for (i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 60.0*i;
	}

	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << " ; ";
		cout << pd2[i] << " at " << &pd2[i] << " ; ";
	}
	delete[] pd1;
	delete[] pd3;
	system("pause");
	return 0;
}