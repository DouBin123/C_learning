# include <iostream>
# include <fstream>
using namespace std;
int main16()
{
	char automobile[50];
	int year;
	double a_price;
	double b_price;
	ofstream outFile;//����һ���������
	outFile.open("carinfi.txt");//���������ļ�����,������һ���ı��ļ���

	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	b_price = 0.913*a_price;
	//***************************���������******************
	/*
boolalpha    ����ʹ�õ��ʡ�true���͡�false����������/����Ĳ���ֵ.
oct    �ð˽��Ƹ�ʽ��ʾ��ֵ.
dec    ��ʮ���Ƹ�ʽ��ʾ��ֵ.
hex    ��ʮ�����Ƹ�ʽ��ʾ��ֵ.
left    �������Ϊ�����.
right    �������Ϊ�Ҷ���.
scientific    �ÿ�ѧ��������ʾ������.
fixed    �������ļ���������ʾ������(���ѧ���������Ӧ).
showbase    ���ʱ��ʾ������ֵ�Ļ���.
showpoint    ��ʾС����Ͷ�����㣬��ʹ����Ҫ.
showpos    �ڷǸ���ֵǰ����ʾ���������ţ���.
skipws    ����һ�������ж�ȡʱ�������հ��ַ�(spaces, tabs, newlines).
unitbuf    ��ÿ�β����Ժ���ջ�����.
internal    ������ַ��ص����ź���ֵ֮��.
uppercase    �Դ�д����ʽ��ʾ��ѧ�������еġ�e����ʮ�����Ƹ�ʽ�ġ�x��.
		
	*/
	
	//cout << fixed<<precision(2)
	cout << fixed;//�������������С����ʽ
	cout.precision(2);//����С������Ϊ����λ
	cout.setf(ios_base::showpoint);//��ʾС����Ͷ����0
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << b_price << endl;

//����������������ʹ��cout���κη���
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile<< "Now asking $" << b_price << endl;

	outFile.close();//�ر��ı��ļ�





	system("pause");
	return 0;
}