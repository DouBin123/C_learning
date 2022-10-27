# include <iostream>
using namespace std;

template <class T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& i) :item(i){ ct++; }
	~HasFriend(){ ct--; }
	friend void counts();
	friend void reports(HasFriend<T>&);
};

//each specialization has its own static data member
template<typename T>
int HasFriend<T>::ct = 0;//静态变量的实例化

//non template friend to all HasFriend <T> classes
void counts()
{
	cout << "int count : " << HasFriend<int>::ct << " ;";
	cout << "double count: " << HasFriend<double>::ct << endl;
}

//non template friend to the HasFriend <int> class
void reports(HasFriend<int> &hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

//non template friend to the HasFriend <double> class
void reports(HasFriend<double> &hf1)
{
	cout << "HasFriend<double>: " << hf1.item << endl;
}


int main6()
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfil(10);
	cout << "After hfil declared: ";
	counts();
	HasFriend<int>hfil2(20);
	cout << "After hfil2 declared: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	reports(hfil);
	reports(hfil2);
	reports(hfdb);
	system("pause");
	return 0;

}


