# include <iostream>
# include <vector>
# include <array>
using namespace std;

int main10()
{
	//*********模板类vector********
	vector<int> vi;//创建一个vector<int>对象vi
	int n;
	cin >> n;
	vector<double>vd(n);//vector<double>对象vd
	//*********模板类array**********
	array <int, 5> ai;
	array <double, 4> ad = { 1.2, 2.1, 3.4, 4.3 };
//比较数组，array,vector
	/*
	1、array、数组存储在栈中，vector存在自由存储区或堆中
	2、array,vector可以整体复制，数组不行
	3、下标为负，表示越界，可以用.at()降低犯错概率
	
	*/
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
	double a6[4];
	//a6 = a1;这里不行
	vector <double> a2(4);
	vector <double> a5(4);
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;
	a5 = a2;
	array<double, 4>a3 = { 3.14, 2.72, 1.62, 1.4 };
	array<double, 4>a4;
	a4 = a3;//数组不能这样写
	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	cout << "a5[2]: " << a5[2] << " at " << &a5[2] << endl;
	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	system("pause");
	return 0;
}