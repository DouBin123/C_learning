# include <iostream>
using namespace std;

//template prototypes
template <typename T>void counts();
template <typename T>void report(T &);

//template class
template <typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT &i) :item(i){ ct++; }
	~HasFriendT(){ ct--; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>&);

};

template<typename T>
int HasFriendT<T>::ct = 0;

//template friend function definitions
template <typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
	cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T & hf)
{
	cout << hf.item << endl;

}
int main7()
{
	counts<int>();
	HasFriendT<int>hfi1(10);
	HasFriendT<int>hfi2(20);
	HasFriendT<double>hfdb(10.5);

	report(hfi1);//generate report (HasFriendT<int> &)
	report(hfi2);
	report(hfdb);
	cout << "counts<int>()output: \n";
	counts<int>();
	cout << "counts<double>()output:\n";
	counts<double>();


	system("pause");
	return 0;

}