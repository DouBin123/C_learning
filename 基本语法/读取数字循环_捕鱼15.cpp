# include <iostream>
using namespace std;
const int Max = 5;
int main15()
{

	//get_data
	double fish[Max];
	cout << "Please enter the weight of your fish.\n";
	cout << "You may enter up to "<<Max
		<<"fish <q to terminate>.\n";
	cout << "fish # 1:";
	int i = 0;
	while ((i < Max)&&  cin >> fish[i])//��������������������i>Max,ֱ�ӽ���ѭ��
	{

		if (++i < Max)
			cout << "\n" << "fish # " << i + 1 << ":" ;
			

	}
		//whileѭ������3
	//calculate average
	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[i];
	if (i == 0)
		cout << "No fish\n";
	else
		cout << "total:" << total << endl;
		cout << total / i << "= average weight of " << i << " fish\n";
	cout << "Done.\n";


	system("pause");
	return 0;
}