# include <iostream>
using namespace std;
int main5()
{
	int nights = 1001;
	int *pt = new  int;//allocate space for an int from heap or free store
	*pt = nights;//store a value there
	cout << "nights value= ";
	cout << nights << ": location = " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pt<< ": location = " << pt << endl;
	//����������int���ڴ棬������nights��ֵ������ڴ�
	delete pt;//�ͷ��ڴ�
	int noon=100;
	int* p;
	p = &noon;//ָ��һ��Ҫ����ַ������ֱ��*p = noon
	cout << "noon value= ";
	cout << noon << ": location = " << &noon << endl;
	cout << "int ";
	cout << "value = " << *p << ": location = " << p<< endl;
	//***********����Ķ�̬����*************
	int size;
	cin >> size;
	int *pz = new int[size];//���� size��int���͵��ڴ棬�������׵�ַ 
	*pz = 5;//��ֵ5����һ��Ԫ�أ��������
	cout << pz[0] << pz[1] << pz[2];//*(pz+k)=pz[k]
	delete[] pz;//�ͷ��ڴ�

	system("pause");
	return 0;
}