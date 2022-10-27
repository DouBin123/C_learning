//write.cpp-----using cout.write()
# include <iostream>
# include <cstring>

int main1()
{
	using namespace std;
	const char* state1 = "Florida";
	const char* state2 = "Kanasas";
	const char* state3 = "Eurphoria";
	int len = strlen(state2);
	cout << "Increasing loop index:\n";
	int i;
	for (i = 1; i <= len; i++)
	{
		cout.write(state2, i);
		cout << endl;
	}

	//concatenate output
	cout << "Decreasing loop index:\n";
	for (i = len; i > 0; i--)
		cout.write(state2, i) << endl;

	//exceed string length
	cout << "Exceeding string lenth:\n";
	cout.write(state2, len + 5) << endl;//输出指定长度的字符串
	system("pause");
	return 0;
}