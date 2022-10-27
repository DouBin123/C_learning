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
	RatedPlayer(unsigned int r = 0, const string & fn = "none", const string &ln = "none", bool ht = false);//�����๹�캯��������ֱ�ӷ��ʻ�������ݳ�Ա��ֻ��ͨ������ĳ�Ա������
	RatedPlayer(unsigned int r, const TableTennisPlayer &tp);//ͨ������ĸ��ƹ��캯����ֵ
	unsigned int Rating() const{ return rating; }
	void ResetRating(unsigned int r){ rating = r; }

};


#endif