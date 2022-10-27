//tabtenn0.h   --a table tennis base class
#ifndef TATENN0_H_
#define TATENN0_H_
#include<string>
using std::string;
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;

public:
	TableTennisPlayer(const string & fn="none",
		const string &ln="none",bool ht=false);
	void Name() const;
	bool HasTable() const{ return hasTable; };
	void ResetTable(bool v){ hasTable = v; };
};

//simple derived class
class RatedPlayer:public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "none", const string &ln = "none", bool ht = false);//派生类构造函数，不能直接访问基类的数据成员，只能通过基类的成员函数。
	RatedPlayer(unsigned int r, const TableTennisPlayer &tp);//通过基类的复制构造函数赋值
	unsigned int Rating() const{ return rating; }
	void ResetRating(unsigned int r){ rating = r; }

};


#endif