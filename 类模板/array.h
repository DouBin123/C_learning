# ifndef ARRAYTP_H_
# define ARRAYTP_H_

# include <iostream>
# include <cstdlib>

template <class T,int n>
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP(){};
	explicit ArrayTP(const T&v);//��ֹ��ʽת��
	virtual T&operator[](int i);
	virtual T operator[](int i)const;
};

template<class T,int n>
ArrayTP<T, n>::ArrayTP(const T&v)
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}
template<class T, int n>
T &ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
		std::cout << "Error in array limits: " << i
		<< " is out of range\n";
	std::exit(EXIT_FAILURE);
	return ar[i];
}

template<class T, int n>
T ArrayTP<T, n>::operator[](int i)const
{
	if (i < 0 || i >= n)
		std::cout << "Error in array limits: " << i
		<< " is out of range\n";
	std::exit(EXIT_FAILURE);
	return ar[i];
}
/*
�ݹ�ʹ�ã�
ArrayTP<ArrayTP<int,5>,10> twodee;
�ȼ�=��int twodee[10][5];

*/


#endif