# include <iostream>
# include <cstring>

int main6()
{

	using namespace std;
	char animal[20] = "bear";
	const char * bird = "wren";//"wren"=s[],bird=s
	char * ps;
	cout << animal << " and ";
	cout << bird << "\n";
	//cout << ps << "\n";//��������psδ��ʼ���ᵼ�±������
	cout << "Enter a kind of animal: ";
	cin >> animal;
	ps = animal;
	cout << ps << "!\n";//ֱ�����fox,��ʹ��animalһ������ӡ�ַ����������ڴ�ӡ�ַ���
	cout << "Before uisng strcpy(): \n";
	cout << animal << " at " << (int*)animal << endl;//ǿ������ת��
	cout << ps << " at " << (int*)ps << endl;
	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);//���յĲ������ַ�����ĵ�ַ
	cout << "After using strcpy(): \n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;
	delete [] ps;


	system("pause");
	return 0;
}
//char a[]={'a','a','a','\0'};
//str___(const char *,const char *,int   a,����)��������<cstring>�У��βξ�Ϊ�ַ�ָ��
//std::string l="asb";//�Զ���ӡ�\0��