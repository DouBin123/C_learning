# include <iostream>
using namespace std;
struct inflatable//�ؼ�����ṹ��    *********�ṹ����
{
	char name[20];
	float volume;
	double price;

}//�������ֱ��д�ṹ���ʵ������
;
int main3()
{
	
	inflatable guest = //*******�ṹ��ʵ������guest��inflatable �ṹ���͵�һ������
	{
		"Glorios Gloria",
		1.88,
		29.99

	};
	inflatable pal = //*******�ṹ��ʵ������pal��inflatable �ṹ���͵���һ������
	{
		"Audiacious Arthur",
		3.12,
		32.99

	};
	//*********************�ṹ����********************
	inflatable gifts[100];//����ĳ�ֽṹ��Ķ��ʵ��������


	inflatable al{ "Arica Dira", 12.56, 19.88 };
	//��ʼ���ṹ��ʱ��������һ�������á������ָ�
	//
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name ;
	cout << " and " << al.name << "!\n";
    cout << "You can have both for $";
	cout << guest.price + pal.price+al.price << "!\n";
//************************������****************
	//struct widget
	//{
	//	char brand[20];
	//	int type;
	//	union id
	//	{
	//		long id_num;
	//		char id_char[20];

	//	} id_val;//�������������ͼ�����
	//};//�����ṹ������
	//widget price ;//ʵ�����ṹ��
	//if (price.type == 1)
	//
	//	cin >> price.id_val.id_num;
 //  else
	//	cin >> price.id_val.id_char;





	system("pause");
	return 0;
}