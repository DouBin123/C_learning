# include <memory>
# include <iostream>
# include <string>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) :str(s)
	{
		std::cout << "Object created!\n";
	}
	~Report(){ std::cout << "Object deleted!\n"; }
	void comment()const{ std::cout << str<<"\n"; }
};

int main5()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}

	system("pause");
	return 0;
}