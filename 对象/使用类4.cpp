# include <iostream>
# include "stock00.h"
int main4()
{
	{
		using std::cout;
		cout << "Using constructors to create new objects\n";
		Stock stock1("NanoSmart", 12, 20.0);//syntax,隐式创建对象
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);//syntax,显式创建对象，会产出临时对象，并将值赋给stock2，随后调用构析函数
		stock2.show();//Stock函数均为初始化

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;
		cout << "Listening stock1 and stock2:\n";
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);//会产出临时对象，并将值赋给stock1，随后调用构析函数，Stock函数为赋值，不是初始化
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done\n";

	
	
	}//该代码块决定了对象的生命周期，如果没有，则代码块为整个main函数，只有在执行完代码块时才会执行构析函数
	system("pause");
	return 0;


}