#ifndef MYTIME0_H_
# define MYTIME0_H_

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);//一般构造函数
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time &t)const;
	Time operator-(const Time &t)const;
	Time operator*(double mult)const;
	//在类声明中定义函数可以直接成为内联函数
	friend Time operator*(double m, const Time &t)
	{
		return t*m;//可以不用理会*左右的数据类型
	}//内联友元函数
	friend std::ostream &operator<<(std::ostream &os, const Time &t);

};
#endif