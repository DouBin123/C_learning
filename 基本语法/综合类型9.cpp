# include <iostream>
struct antarctica_years_end
{
	int year;
	/*其他类型的数据*/
};
/*
int a[5]
int *p=a;
a的类型是int[5] 数组
&a的类型是int(*)[5] 指针——指向int[5]数组的指针
&a[0]的类型是int* 指针——指向int类型的指针
a[k]=*（p+k）
*/
int main9()
{
	antarctica_years_end s01, s02, s03;
	s01.year = 1998;
	antarctica_years_end *pa = &s02;//结构体要取地址
	pa->year = 1999;
	antarctica_years_end trio[3];//数组名等价于指向数组首元素的指针
	trio[0].year = 2003;
	std::cout << trio->year << std::endl;
	const antarctica_years_end *arp[3] = { &s01, &s02, &s03 };
	std::cout << arp[1]->year << std::endl;
	const antarctica_years_end **ppa = arp;//ppa指向arp,arp指向s01,s02,s03
	auto ppb = arp;
	std::cout <<"ppb: "<< ppb << std::endl;
	std::cout << "arp: " << arp << std::endl;
	std::cout << (*ppa)->year << std::endl;//*ppa=arp
	std::cout << (*(ppb + 1))->year <<std:: endl;//*（ppb+1）=arp[1]即&s02
	system("pause");
	return 0;
}