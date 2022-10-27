# include <cstring>
# include "dma.h"

//baseDMA method
baseDMA::baseDMA(const char *l, int r)//构造函数初始化赋值，将字符串及指针赋给私有变量，而不仅仅是指针
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA &rs)//类似复制构造函数，缺少=
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
baseDMA::~baseDMA()
{
	delete[] label;//因为构造函数使用了new [] 

}
baseDMA &baseDMA::operator=(const baseDMA &rs)
{
	if (this == &rs)
		return *this;
	delete[]label;//删除即将被赋值的对象中之前的存储的地址，释放内存
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
hasDMA::hasDMA(const hasDMA &hs)//调用基类的复制构造函数
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
