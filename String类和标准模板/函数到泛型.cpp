# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;

bool MySort(int a, int b)
{

	return a < b;
}
void Display(int a)
{
	cout << a << ' ';
}
template<class T>
inline bool MySort(T const&a, T const& b)
{

	return a < b;
}
template<class T>
inline void Display(T const &a)
{
	cout << a << ' ';
}
struct SortF
{
	bool operator()(int a,int b)
	{
		return a < b;
	}
};
class DisplayF
{
public:
	void operator()(int a)
	{
		std::cout << a << ' ';
	}
};
template<class T>
struct SortTF
{
	inline bool operator()(T const & a, T const &b)
	{
		return a < b;
	}
};
template<class T>
class DisplayTF
{
public:
	inline void operator()(T const & a)
	{
		std::cout << a << ' ';
	}
};
int main22()
{
	//c++方式
	int arr[] = { 3, 4,5, 6, 7 };
	sort(arr, arr + 5, MySort);
	for_each(arr, arr + 5, Display);
	cout << endl;

	//c++泛型
	int arr2[] = { 3, 4, 5, 6, 7 };
	sort(arr2, arr2 + 5, MySort<int>);
	for_each(arr2, arr2 + 5, Display<int>);
	cout << endl;
	//仿函数
	//重载（）
	int arr3[] = { 3, 4, 5, 6, 7 };
	sort(arr3, arr3 + 5, SortF());
	for_each(arr3, arr3 + 5, DisplayF());
	cout << endl;
	//模板仿函数
	int arr4[] = { 3, 4, 5, 6, 7 };
	sort(arr4, arr4 + 5, SortTF<int>());
	for_each(arr4, arr4 + 5, DisplayTF<int>());
	cout << endl;

	system("pause");
	return 0;

}