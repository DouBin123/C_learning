# include <iostream>
struct antarctica_years_end
{
	int year;
	/*�������͵�����*/
};
/*
int a[5]
int *p=a;
a��������int[5] ����
&a��������int(*)[5] ָ�롪��ָ��int[5]�����ָ��
&a[0]��������int* ָ�롪��ָ��int���͵�ָ��
a[k]=*��p+k��
*/
int main9()
{
	antarctica_years_end s01, s02, s03;
	s01.year = 1998;
	antarctica_years_end *pa = &s02;//�ṹ��Ҫȡ��ַ
	pa->year = 1999;
	antarctica_years_end trio[3];//�������ȼ���ָ��������Ԫ�ص�ָ��
	trio[0].year = 2003;
	std::cout << trio->year << std::endl;
	const antarctica_years_end *arp[3] = { &s01, &s02, &s03 };
	std::cout << arp[1]->year << std::endl;
	const antarctica_years_end **ppa = arp;//ppaָ��arp,arpָ��s01,s02,s03
	auto ppb = arp;
	std::cout <<"ppb: "<< ppb << std::endl;
	std::cout << "arp: " << arp << std::endl;
	std::cout << (*ppa)->year << std::endl;//*ppa=arp
	std::cout << (*(ppb + 1))->year <<std:: endl;//*��ppb+1��=arp[1]��&s02
	system("pause");
	return 0;
}