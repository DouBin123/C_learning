# include <iostream>
using namespace std;
int main11()
{
	double prices[5] = { 4.99, 10.99, 6.87, 7.95, 8.49 };
	for (double x : prices)
	{
		cout << x << endl;
	}
	//�ڱ��ַ�
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:\n";
	//cin >> ch;
	cin.get(ch);
	while (ch != '#')
	{
		cout.put(ch);
		++count;
		//cin >> ch;//��������,�������س��ո��Ʊ��
		cin.get(ch);//

	}
	cout << endl << count << "characters read\n";


	system("pause");
	return 0;
}