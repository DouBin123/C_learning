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
	char *buffer= new char[BUF];//buffer �洢  &char [BUF],�ڴ��
	cout << "Memory block addresses:\n" << "buffer: " 
	<< (void*)buffer << endl;//00A5EF58
	JustTesting *pc1, *pc2;
	pc1 = new (buffer)JustTesting;//place object in buffer
	//pc1Ϊ��ָ�����ڴ��buffer�л���һС�����ʼ��ַ��buffer��ͬ
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
	//pc3 = new(buffer)JustTesting("Bad Idea", 6);//�����˸��ڴ��֮ǰ������
	pc3 = new(buffer+sizeof(JustTesting))JustTesting("Bad Idea", 6);//����ƫ����
	pc4 = new JustTesting("Heap2 ", 10);

	cout << "Memory contents:\n";
	cout << pc3 << ": ";
	pc3->show();

	delete pc2;
	delete pc4;
	//���ڶ�λnew�����Ķ���Ӧ�����봴��˳���෴��˳�����ɾ��
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[]buffer;
	cout << "Done\n";
	
	system("pause");
	return 0;


}

