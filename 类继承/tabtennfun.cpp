# include <iostream>
# include "tabtenn.h"

TableTennisPlayer::TableTennisPlayer(const string &fn, 
	const string &ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht){}
//这里形参为const string &调用的是string标准构造函数，若形参为const string*则是一般的string构造函数
void TableTennisPlayer::Name()const
{
	std::cout << lastname << ", " << firstname;
}

//RatedPlayer method
RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
	const string &ln, bool ht) :TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp), rating(r)
{
}