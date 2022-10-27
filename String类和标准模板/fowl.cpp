//fowl.cpp---auto_ptr a poor choice
# include <iostream>
# include <string>
# include <memory>

int main6()
{
	using namespace std;
	auto_ptr<string> films[5]=
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Bubi")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Eggs")),
	};
	//auto_ptr<string>pwin;//指针对象
	//shared_ptr<string> pwin;//c++11,引用计数从1加到2，
	                       //然后shared_ptr数组成员被释放，再调用films[2]的析构函数，将引用计数降为0，释放以前的内存
	//pwin = films[2];//auto_ptr,films[2]loses ownership,films[2]is null,cause default

	cout << "The nominees for best avian baseball film are\n";;
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	//cout << "The winner is " << *pwin << "!\n";
	
	system("pause");
	return 0;
}