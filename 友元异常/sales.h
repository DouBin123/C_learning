# include <stdexcept>
# include <string>

class Sales
{
public:
	enum{ MONTH = 12 };
	class bad_index : public std::logic_error
	{
	private:
		int bi;
	public:
		explicit bad_index(int ix,
			const std::string &s = "Index error in Sales object\n");//常量字符串初始化第二个参数，不会被改变
		int bi_val()const { return bi; }
		virtual ~bad_index()throw(){}
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double *gr, int n);
	virtual ~Sales(){}
	int Year()const { return  year; }
	virtual double operator[](int i)const;//读
	virtual double & operator[](int i);//写
private:
	double gross[MONTH];
	int year;
};

class LabeledSales :public Sales
{
public:
	class nbad_index : public Sales::bad_index
	{
	private:
		std::string lb1;
	public:
		nbad_index(const std::string &lb, int ix,
			const std::string &s = "Index error in LabeledSales object\n");
		const std::string & label_val()const{ return lb1; }
		virtual ~nbad_index()throw(){}
	};
	explicit LabeledSales(const std::string & lb = "none", int yy = 0);
	LabeledSales(const std::string &lb, int yy, const double *gr, int n);
	virtual ~LabeledSales(){}
	const std::string &Label()const { return label; }
	virtual double operator[](int i)const;//读
	virtual double & operator[](int i);//写
private:
	std::string label;
};