//random.cpp---random access to a binary file
# include <iostream>
# include <fstream>
# include <iomanip>
# include <cstdlib>
const int	limit = 20;
struct planet1
{
	char name[limit];
	double population;
	double g;
};

const char* file2 = "planets.dat";//assumed to exist
inline void eatlines1(){ while (std::cin.get() != '\n')continue; }
//�س��ж��������

int main16()
{
	using namespace std;
	planet1 p1;
	cout << fixed;
/*
	��������
	�����ļ���
		�򿪷�ʽ
	���ļ���
		��ȡ�ļ�ֱ���ļ�β����
			�ƶ��ļ�ָ�뵽��Ӧ��λ�ã���ʼ��ȡ
		���ļ�β����eofbit�������´η���
		�쳣�������ļ�β��
	δ���ļ���
	��λ�ı��ļ����ݣ�
		��λҪ�ı���������ļ��е�λ��
		��ȡҪ�ı������
		����Ҫ�ı������
			д��ʧ�ܵĲ���
		������ʾ�ļ�
			�ƶ��ļ�ָ������ʼ
			��ȡ�ļ�/ʧ��

*/
	//show initial contents
	fstream finout;//read and write stream
	finout.open(file2, ios_base::out | ios_base::in | ios_base::binary);//conection
	int ct = 0;//��¼��
	
	if (finout.is_open())
	{
		finout.seekg(0);//go to beginning
		cout << "Here are the current contents of the "
			<< file2 << " file:\n";
		while (finout.read((char*)&p1, sizeof p1))//read the file to program
		{
			cout << ct++ << ": " << setw(limit) << p1.name << ": "//��¼��ȡ�Ľṹ����������������Ļ
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}//��ȡ�ļ���ֱ��β����eofbit��λ
		if (finout.eof())
				finout.clear();//������״̬֮�󣬳��������ٴη��ʸ��ļ���else���ִ���������ԭ���ļ�β�Ĳ���
		else
		{
			cerr << "Error in reading " << file2 << ".\n";
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		cerr << file2 << " Could not be opened --bye,\n";
		exit(EXIT_FAILURE);
	}

	//change a record
	cout << "Enter the record number you wish to change: ";
	long rec;//record
	cin >> rec;
	eatlines1();//get rid of(��ȥ) newline
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number --bye\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof p1;//convert to streampos type
	finout.seekg(place);//random access
	if (finout.fail())//fail to read  set failbit
	{
		cerr << "Error on attempted seek\n";
		exit(EXIT_FAILURE);
	}
	//show the change to screen
	finout.read((char*)&p1, sizeof p1);//��ȡҪ�ı��һ����Ŀ
	cout << ct++ << ": " << setw(limit) << p1.name << ": "
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(2) << setw(6) << p1.g << endl;
	if (finout.eof())
		finout.clear();
	//����ı����Ϣ
	cout << "Enter planet name: ";
	cin.get(p1.name, limit);
	eatlines1();
	cout << "Enter planetary population: ";
	cin >> p1.population;
	cout << "nter planet's acceleration of gravity: ";
	cin >> p1.g;
	//����������洢�ڳ���
	//�ٽ�������Ϣ������ļ�ָ��λ��
	finout.seekp(place);//go to back
	finout.write((char*)&p1, sizeof p1) << flush;//ˢ�»�����
	if (finout.fail())
	{
		cerr << "Error on attempted write\n";
		exit(EXIT_FAILURE);
	}
	//show revised file
	ct = 0;
	finout.seekg(0);
	cout << "Her are the new contents of the " << file2 << " file:\n";
	while (finout.read((char*)&p1, sizeof p1))
	{
		cout << ct++ << ": " << setw(limit) << p1.name << ": "
			<< setprecision(0) << setw(12) << p1.population
			<< setprecision(2) << setw(6) << p1.g << endl;
	}
	finout.close();
	cout << "Done!\n";


	

	system("pause");
	return 0;
}
