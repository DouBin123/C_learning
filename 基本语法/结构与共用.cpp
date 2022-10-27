# include <iostream>
using namespace std;
struct inflatable//关键字与结构名    *********结构声明
{
	char name[20];
	float volume;
	double price;

}//这里可以直接写结构体的实例变量
;
int main3()
{
	
	inflatable guest = //*******结构体实例化，guest是inflatable 结构类型的一个变量
	{
		"Glorios Gloria",
		1.88,
		29.99

	};
	inflatable pal = //*******结构体实例化，pal是inflatable 结构类型的另一个变量
	{
		"Audiacious Arthur",
		3.12,
		32.99

	};
	//*********************结构数组********************
	inflatable gifts[100];//创建某种结构体的多个实例化对象


	inflatable al{ "Arica Dira", 12.56, 19.88 };
	//初始化结构体时，与数组一样，利用“，”分隔
	//
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name ;
	cout << " and " << al.name << "!\n";
    cout << "You can have both for $";
	cout << guest.price + pal.price+al.price << "!\n";
//************************共用体****************
	//struct widget
	//{
	//	char brand[20];
	//	int type;
	//	union id
	//	{
	//		long id_num;
	//		char id_char[20];

	//	} id_val;//创建共用体类型及变量
	//};//创建结构体类型
	//widget price ;//实例化结构体
	//if (price.type == 1)
	//
	//	cin >> price.id_val.id_num;
 //  else
	//	cin >> price.id_val.id_char;





	system("pause");
	return 0;
}