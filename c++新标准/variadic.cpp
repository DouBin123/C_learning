//variadic.cpp
# include <iostream>
# include <string>

//definition for 0 parameters
void show_list() {}

//definition for 1 parameters
template<typename T>
void show_list(const T& value)
{
	std::cout << value << '\n';
}
//definition for 2 or more parameters
template <typename T, typename... Args>
void show_list(const T& value, const Args& ...args)
{
	std::cout << value << " , ";
	show_list(args...);//???ٲ????ݹ?
}

int main8()
{
	int n = 14;
	double x = 2.71828;
	std::string mr = "Mr. String objects??";
	show_list(n,x);
	show_list(x * x, '!', 7, mr);
	return 0;
}