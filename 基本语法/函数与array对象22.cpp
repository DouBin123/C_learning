# include <iostream>
# include <array>
# include <string>
//����ɷ��鰴insert��
const int Season = 4;
const std::array<std::string, Season>Snames =
{ "Spring", "Summer", "Fall", "Winter" };//function to modify array object
//Snames ��array�����һ��ʵ�������ĸ�Ԫ�ص��ַ�������
void fill(std::array<double, Season>*pa);//����ĵ�ַ���� function that uses array object without modifying it
void show(std::array<double, Season>da);//�����ֵ����
using namespace std;
int main22()
{
	array<double, Season>expenses;
	fill(&expenses);
	show(expenses);


	system("pause");
	return 0;


}
void fill(std::array<double, Season>*pa)
{
	using namespace std;
	for (int i = 0; i < Season; i++)
	{
		cout << "Enter" << Snames[i] << "expenses: ";
		cin >> (*pa)[i];
	}

}
void show(std::array<double, Season>da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Season; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;

}