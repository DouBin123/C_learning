//variadic.cpp--using recursion to unpack a parameter pack
# include <iostream>
# include <string>
//definition for 0 parameters--terminating call
void show_list3() {}

//definition for 1 or more parameters
template <typename T, typename ...Args>//Args is a template parameter pack
void show_list3(T value, Args  ...args)//args is a funtion parameter pack
{
	std::cout << value << " , ";
	show_list3(args...);
}

int main7()
{
	int n = 14;
	double x = 2.71828;
	std::string mr = "Mr. String objects.";
	show_list3(n, x);
	show_list3(x * x, '!', 7, mr);
	return 0;
	//输出的每项都有一个逗号，采用只有一个参数时，另设置模板
}