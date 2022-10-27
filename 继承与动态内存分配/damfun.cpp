# include <cstring>
# include "dma.h"

//baseDMA method
baseDMA::baseDMA(const char *l, int r)//���캯����ʼ����ֵ�����ַ�����ָ�븳��˽�б���������������ָ��
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA &rs)//���Ƹ��ƹ��캯����ȱ��=
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
baseDMA::~baseDMA()
{
	delete[] label;//��Ϊ���캯��ʹ����new [] 

}
baseDMA &baseDMA::operator=(const baseDMA &rs)
{
	if (this == &rs)
		return *this;
	delete[]label;//ɾ����������ֵ�Ķ�����֮ǰ�Ĵ洢�ĵ�ַ���ͷ��ڴ�
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}
std::ostream & operator<<(std::ostream &os,const baseDMA &rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}
//lacksDMA method
lacksDMA::lacksDMA(const char *c, const char*l, int r) :baseDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';

}
lacksDMA::lacksDMA(const char *c, const baseDMA &rs) :baseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0'; 
}
std::ostream & operator<<(std::ostream & os, const lacksDMA &ls)
{
	os << (const baseDMA &)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}

//hasDMA method
hasDMA::hasDMA(const char*s, const char*l, int r) :baseDMA(l,r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);

}
hasDMA::hasDMA(const char*s, const baseDMA &rs) :baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);

}
hasDMA::hasDMA(const hasDMA &hs)//���û���ĸ��ƹ��캯��
{
	style = new char[std::strlen(hs.style) + 1];
	strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
	delete[]style;

}
hasDMA & hasDMA::operator=(const hasDMA &hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);
	delete[]style;//prepare for new style
	style = new char[std::strlen(hs.style) + 1];
	strcpy(style, hs.style);
	return *this;
}
std::ostream & operator<<(std::ostream &os, const hasDMA &hs)
{
	os << (const baseDMA &)hs << std::endl;
	os << "Style: " << hs.style << std::endl;
	return os;
}
