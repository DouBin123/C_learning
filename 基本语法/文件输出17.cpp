# include <iostream>
# include <fstream>//file I/O support
# include <cstdlib>//support for exit()
const int SIZE = 60;
using namespace std;
int main17()
{
	char filename[SIZE];
	ifstream inFile;//creat a object for input
	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);//associate  object with file
	if (!inFile.is_open())//fail to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);


	}
	double value;
	double sum = 0.0;
	int count=0;

	inFile >> value;
	while (inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;//按double 类型读取文本数据

	}
	if (inFile.eof())//程序读取文件不应该超过EOF
		cout << "End of file reached.\n";
	else if (inFile.fail())//检查类型是否匹配
		cout << "Input terminate by data mis match.\n";
	else
		cout << "Input terminate for unknow reason.\n";
	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	inFile.close();

	system("pause");
	return 0;

}
