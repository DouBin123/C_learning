# include <iostream>
# include <vector>
# include <array>
using namespace std;

int main10()
{
	//*********ģ����vector********
	vector<int> vi;//����һ��vector<int>����vi
	int n;
	cin >> n;
	vector<double>vd(n);//vector<double>����vd
	//*********ģ����array**********
	array <int, 5> ai;
	array <double, 4> ad = { 1.2, 2.1, 3.4, 4.3 };
//�Ƚ����飬array,vector
	/*
	1��array������洢��ջ�У�vector�������ɴ洢�������
	2��array,vector�������帴�ƣ����鲻��
	3���±�Ϊ������ʾԽ�磬������.at()���ͷ������
	
	*/
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
	double a6[4];
	//a6 = a1;���ﲻ��
	vector <double> a2(4);
	vector <double> a5(4);
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;
	a5 = a2;
	array<double, 4>a3 = { 3.14, 2.72, 1.62, 1.4 };
	array<double, 4>a4;
	a4 = a3;//���鲻������д
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