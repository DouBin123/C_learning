# include <iostream>
using namespace std;

template <typename T>
class Manfriend
{
private:
	T item;
public:
	Manfriend(const T & i) :item(i){};
	template <typename C, typename D>friend void show2(C &, D &);
};
template <typename C, typename D> void show2(C &c, D &d)
{
	cout << c.item << ", " << d.item << endl;

}

int main()
{
	Manfriend<int>hfi1(10);
	Manfriend<int>hfi2(20);
	Manfriend<double>hfdb(10.5);
	cout << "hfi1,hfi2: ";
	show2(hfi1, hfi2);
	cout << "hfdb,hfi2";
	show2(hfdb, hfi2);

	system("pause");
	return 0;
}