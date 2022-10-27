//listrmv.cpp-----applying the STL to a string
# include <iostream>
# include <list>
# include <algorithm>
void Show3(int);
const int LIMS = 10;

int main16()
{
	using namespace std;
	int ar[LIMS] = { 4, 5, 6, 4, 4, 5, 6, 6, 7, 7 };
	list<int>la(ar, ar + LIMS);
	list<int>lb(la);
	cout << "Original list contents:\n\t";
	for_each(la.begin(), la.end(), Show3);
	cout << endl;
	la.remove(4);//ɾ��Ԫ��4
	cout << "After using  remove method():\n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show3);
	cout << endl;
	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);//�����а���4�ı�ɾ������Ԫ�ظ�����Ȼ���䣬����һ��ָ��βֵ�ĵ���������ʹ��erase()ɾ������
	cout << "After using the remove() function:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show3);
	cout << endl;
	lb.erase(last, lb.end());
	cout << "After using the erase() method:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show3);
	cout << endl;


	system("pause");
	return 0;
}
void Show3(int v)
{
	std::cout << v << ' ';
}
