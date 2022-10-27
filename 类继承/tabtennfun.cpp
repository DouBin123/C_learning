# include <iostream>
# include "tabtenn.h"

TableTennisPlayer::TableTennisPlayer(const string &fn, 
	const string &ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht){}
//�����β�Ϊconst string &���õ���string��׼���캯�������β�Ϊconst string*����һ���string���캯��
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