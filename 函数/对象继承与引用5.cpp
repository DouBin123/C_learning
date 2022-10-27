/*
ʹ�����ò����ļ��������
1�������޸ĵ��ò����е����ݶ���
2��ͨ���������ö��������ݶ��󣬿�����߳���������ٶȣ��ϴ�Ľṹ�������
*/
//*****************ֵ���������ô��ݺ�ָ�봫��********
/*
1��������ݶ����С���������������ͻ�С�ͽṹ����ֵ����
2�����ݶ��������飬ʹ��constָ��
3�����ݶ����ǽϴ�Ľṹ��ʹ��const ָ��� const ���ã����Խ�ʡ��������Ҫ��ʱ��Ϳռ�
4�����ݶ����������ʹ��const����
*/
//*******************�޸ĵ��ú������ݵĺ���*********
/*
1�����ݶ����������������ͣ�ʹ��ָ��
2�����ݶ��������飬ֻ��ʹ��ָ��
3�����ݶ����ǽṹ����ʹ�����û�ָ��
4�����ݶ����������ʹ������
*/

# include <iostream>
# include <fstream>
# include<cstdlib>
using namespace std;
void file_it(ostream &os, double fo, const double fe[], int n);
const int LIMIT = 5;
//ofstream�������࣬ostream�ǻ��࣬���ofstream�Ķ���fout�������ö���(os)����ʹ�û���ķ���
//������̳��˻���ķ������������ÿ���ָ�����������
int main5()
{
	ofstream fout;
	const char *fn = "ep_data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open" << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}	
	double objective;
	cout << "Enter the focal length of your""telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal length ,in mm,of " << LIMIT << "eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepieces # " << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);//д���ļ�
	file_it(cout, objective, eps, LIMIT);//��ʾ
	cout << "Done\n";
	system("pause");
	return 0;


}
//����os���������� ostream &���� �ȿ���ָ��ostream����cout��,�ֿ���ָ��ofstream����fout��
void file_it(ostream &os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;//�洢ʹ�ú���֮ǰ����Ϣ����������,û�еĻ���ɿ�ѧ��������ʾ
	initial = os.setf(ios_base::fixed);//���������Ϊ���������ʽ
	os.precision(0);
	os << "Focal length of objective: " << fo << "mm\n";//1800��С�����
	os.setf(ios::showpoint);
	os.precision(1);//һλС��
	//os.width(12);
	os << "f.1. eyepieces";
	//os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);//��ԭ��������
}
/*
ios_base::flags����ȡ/�������ĸ�ʽ��
ios_base::setf���������ĸ�ʽ����ԭ�и�ʽ�ϲ���
ios_base::unsetf�����ݲ���mask��������ĸ�ʽ��ĳЩλ��bit����
ios_base::precision����ȡ / ������ʾ������ʱ�ľ��ȡ�
ios_base::width����ȡ / �趨����������ݵ���ʾ��ȡ�
*/