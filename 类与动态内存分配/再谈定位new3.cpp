# include <iostream>
# include <string>
# include <new>
using namespace std;
const int BUF = 512;
class JustTesting
{
public:
	JustTesting(const string &s = "Just Tesing", int n = 0)
	{
		words = s; number = n; cout << words << " constructed\n";
	};
	~JustTesting()
	{
		cout << words << " destroyed\n";
	};
	void show()const
	{
		cout << words << ", " << number << endl;
	}
private:
	string words;
	int number;
};
int main()
{
	char *buffer= new char[BUF];//buffer 存储  &char [BUF],内存池
	cout << "Memory block addresses:\n" << "buffer: " 
	<< (void*)buffer << endl;//00A5EF58
	JustTesting *pc1, *pc2;
	pc1 = new (buffer)JustTesting;//place object in buffer
	//pc1为在指定的内存块buffer中划出一小块的起始地址与buffer相同
	cout << pc1 << endl;
	pc2 = new JustTesting("Heap1", 20);
	cout << "Memory block addresses:\n" << "buffer: "
		<< (void*)buffer << "  heap: " << pc2 << endl;
	//(void*)buffer=&char [BUF]
	cout << "Memory contents:\n";
	cout << pc1 << ": ";
	pc1->show();
	cout << pc2 << ": ";
	pc2->show();

	JustTesting *pc3, *pc4;
	//pc3 = new(buffer)JustTesting("Bad Idea", 6);//覆盖了该内存块之前的数据
	pc3 = new(buffer+sizeof(JustTesting))JustTesting("Bad Idea", 6);//具有偏移量
	pc4 = new JustTesting("Heap2 ", 10);

	cout << "Memory contents:\n";
	cout << pc3 << ": ";
	pc3->show();

	delete pc2;
	delete pc4;
	//对于定位new创建的对象，应该以与创建顺序相反的顺序进行删除
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[]buffer;
	cout << "Done\n";
	
	system("pause");
	return 0;


}

