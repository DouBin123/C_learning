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
//回车判断输入结束

int main16()
{
	using namespace std;
	planet1 p1;
	cout << fixed;
/*
	创建流；
	关联文件：
		打开方式
	打开文件：
		读取文件直到文件尾部：
			移动文件指针到相应的位置，开始读取
		到文件尾部清eofbit，方便下次访问
		异常操作到文件尾部
	未打开文件；
	定位改变文件内容：
		定位要改变的内容在文件中的位置
		读取要改变的内容
		键入要改变的内容
			写入失败的操作
		重新显示文件
			移动文件指针至开始
			读取文件/失败

*/
	//show initial contents
	fstream finout;//read and write stream
	finout.open(file2, ios_base::out | ios_base::in | ios_base::binary);//conection
	int ct = 0;//记录号
	
	if (finout.is_open())
	{
		finout.seekg(0);//go to beginning
		cout << "Here are the current contents of the "
			<< file2 << " file:\n";
		while (finout.read((char*)&p1, sizeof p1))//read the file to program
		{
			cout << ct++ << ": " << setw(limit) << p1.name << ": "//记录读取的结构体个数，并输出在屏幕
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}//读取文件，直到尾部，eofbit置位
		if (finout.eof())
				finout.clear();//重置流状态之后，程序便可以再次访问该文件，else部分处理因其他原因到文件尾的操作
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
	eatlines1();//get rid of(除去) newline
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
	finout.read((char*)&p1, sizeof p1);//读取要改变的一个项目
	cout << ct++ << ": " << setw(limit) << p1.name << ": "
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(2) << setw(6) << p1.g << endl;
	if (finout.eof())
		finout.clear();
	//输入改变的信息
	cout << "Enter planet name: ";
	cin.get(p1.name, limit);
	eatlines1();
	cout << "Enter planetary population: ";
	cin >> p1.population;
	cout << "nter planet's acceleration of gravity: ";
	cin >> p1.g;
	//将键盘输入存储在程序
	//再将程序信息输出到文件指定位置
	finout.seekp(place);//go to back
	finout.write((char*)&p1, sizeof p1) << flush;//刷新缓存区
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
