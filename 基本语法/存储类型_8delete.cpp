# include <iostream>
# include <cstring>
using namespace std;
//�ú�������һ��ָ���ַ�����ָ�룬���ַ�������һ�����͵���ʱ�����У���
//new����һ���պÿ��Դ洢�����ڴ棬���ظ��ڴ���ָ�룬��ʡ�������ڴ�ռ�
char * getname();//��������
int main8()
{
	char *name;
	name = getname();
	cout << name << " at " << (int*)name << "\n";
	delete [] name;
	name = getname();//�ظ�����֮ǰ���ڴ�
	cout << name << " at " << (int*)name << "\n";
	delete[] name;
//***********************�Զ��洢����̬�洢����̬�洢************8
//�Զ��洢���ں����ڲ�����ĳ���������ڵ��ú���ʱ���������ý����Զ����٣�����ȳ�
//��̬�洢������������ִ���ڼ䶼���ڣ�static
//��̬�洢�� ����һ���ڴ�أ���Ϊ���ɴ洢�ռ��ѣ���ǰ���ֱ������ڴ��Ƕ����ģ���û�м�ʱ delete������ڴ�й©����ʹ����
	//ָ����ڴ汻�ͷţ����ڴ�ص���Ȼ���ڣ������޷����ʣ�Ҫ���������������
	system("pause");
	return 0;
}
char * getname()
{
	char temp[80];
	cout << "Enter last name: ";
	cin >> temp;
	char *pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);
	return pn;
}
