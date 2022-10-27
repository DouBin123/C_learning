# include <iostream>
# include <cstring>
using namespace std;
//该函数返回一个指向字符串的指针，将字符串读入一个大型的临时数组中，用
//new创建一个刚好可以存储它的内存，返回该内存块的指针，节省大量的内存空间
char * getname();//函数声明
int main8()
{
	char *name;
	name = getname();
	cout << name << " at " << (int*)name << "\n";
	delete [] name;
	name = getname();//重复利用之前的内存
	cout << name << " at " << (int*)name << "\n";
	delete[] name;
//***********************自动存储、静态存储、动态存储************8
//自动存储：在函数内部定义的常规变量，在调用函数时产生，调用结束自动销毁，后进先出
//静态存储：在整个程序执行期间都存在，static
//动态存储： 管理一个内存池，称为自由存储空间或堆，与前两种变量的内存是独立的，若没有及时 delete会造成内存泄漏，即使包含
	//指针的内存被释放，但内存池的仍然存在，而且无法访问，要避免出现这种现象。
	system("pause");
	return 0;
}
char * getname()
{
	char temp[80];
	cout << "Enter last name: ";
	cin >> temp;
	char *pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);
	return pn;
}
