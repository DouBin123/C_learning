//binary.cpp---binary file IO
# include <iostream>
# include <fstream>
# include <iomanip>
# include <cstdlib>

inline void eatlines() { while (std::cin.get() != '\n')continue; }
struct planet
{
	char name[20];//���ﲻ����ʹ��string��string�������������ַ�����
	//���ǰ���һ��ָ�����д洢���ַ������ڴ浥Ԫ��ָ�롣��˽��ṹ���Ƶ��ļ���ʱ�����ƵĽ������ַ������ݣ������ַ����ĵ�ַ���ٴ����г���ʱ���õ�ַ���������塣
	double population;
	double g;
};

const char* file = "planets.dat";

int main15()
{
	using namespace std;
	planet p1;
	cout << fixed << right;
	//show initial contents
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	//NOTE:some systems don't accept the ios_base::binary mode
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.read((char*)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	//add new data
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	//NOTE: some systems don't accept the ios_base::binary mode 
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output:\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		eatlines();
		cout << "Enter planetary population: ";
		cin >> p1.population;
		eatlines();
		cout << "Enter planet's acceleration of gravity: ";
		cin >> p1.g;
		eatlines();
		fout.write((char*)&p1, sizeof p1);
		cout << "Enter plannet name (enter a blank line "
			"to quit): \n";
		cin.get(p1.name, 20);
	}

	//show revised file
	fin.clear();
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.read((char*)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	cout << "Done!\n";


	system("pause");
	return 0;
}