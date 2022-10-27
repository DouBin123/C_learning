# include <iostream>
# include "stock00.h"

const int STKS = 4;
int main5()
{

	Stock stocks[STKS] = {
		Stock("NanoSmart",12 ,20.0 ),//调用一般构造函数
		Stock("Boffo Objects",200,20.0),
		Stock("Monolithic Obelisks",130,20.1),
		Stock("Fleep Enterprise",60,6.5)
	};
	std::cout << "Stock holding:\n";
	int st;
	for (st = 0; st < STKS; st++)
	{
		stocks[st].show();
	}
	const Stock *top = &stocks[0];//top指向第1个对象地址，与结构体类似
	for (st = 1; st < STKS; st++)
		top = &(top->topval(stocks[st]));//&优先级低于—>,(top->topval(stocks[st]))==对象.topval(stocks[st]),是最值
	std::cout << " \nMost valuable holding:\n";
	top->show();


	system("pause");
	return 0;

}