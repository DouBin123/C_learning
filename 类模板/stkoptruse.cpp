# include <iostream>
# include <cstdlib>
# include <ctime>
# include "stackp.h"
const int Num = 10;

int main2()
{
	std::srand(std::time(0));
	std::cout << "Please enter stack size: ";
	int stacksize;
	std::cin >> stacksize;

	//create an empty stack with stacksize slots
	Stack<const char*>st(stacksize);

	const char * in[Num] = {
		"1:Hank Gilgamesh", "2:Kiki Iahstar",
		"3:Betty Rocker", "4:Ian Flageanti",
		"5:Wolfgang Kibble", "6:Portia Koop",
		"7:Joy Almondo", "8:Xaverie Paprika",
		"9:Juan Moore", "10:Mish Mavhe"
	};
	//out basket
	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed<Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand()%2&&nextin<Num)//rand()·µ»ØÕûÊý
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
	{
		std::cout << out[i] << std::endl;
	}
	std::cout << "Bye.\n";

	system("pause");
	return 0;

}