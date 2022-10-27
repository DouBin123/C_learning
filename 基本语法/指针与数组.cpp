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
	//首先申请了int的内存，并复制nights的值给这块内存
	delete pt;//释放内存
	int noon=100;
	int* p;
	p = &noon;//指针一定要给地址，不能直接*p = noon
	cout << "noon value= ";
	cout << noon << ": location = " << &noon << endl;
	cout << "int ";
	cout << "value = " << *p << ": location = " << p<< endl;
	//***********数组的动态联编*************
	int size;
	cin >> size;
	int *pz = new int[size];//申请 size个int类型的内存，并返回首地址 
	*pz = 5;//赋值5给第一个元素，其余随机
	cout << pz[0] << pz[1] << pz[2];//*(pz+k)=pz[k]
	delete[] pz;//释放内存

	system("pause");
	return 0;
}