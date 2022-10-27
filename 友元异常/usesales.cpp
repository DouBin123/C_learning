# include <iostream>
# include "sales.h"
using namespace std;
int main9()
{
	double vals1[12] =
	{
		120, 111, 333, 444, 555, 556,
		444, 333, 456, 765, 256, 789
	};
	double vals2[12] =
	{
		12, 13, 23, 34, 45, 56,
		65, 87, 87, 99, 45, 34
	};

	Sales sales1(2011, vals1, 12);//2011年度月销售额
	LabeledSales sales2("Blogstar", 2012, vals2, 12);//2012年含标签月销售额

	cout << "First try block:\n";
	try{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales1[i] << ' ';//Sales::operator[](i)
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales2[i] << ' ';//空一格
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1\n";
	}
	catch (LabeledSales::nbad_index &bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index &bad)
	{
		cout << bad.what();
		cout << "bad.index: " << bad.bi_val() << endl;
	}
	cout << "\nNext try block:\n";
	try{
		sales2[2] = 37.5;
		sales2[23] = 90;
		sales1[20] = 23345;//out_of_bounds error
		cout << "End of try block 2.\n";
	}
	catch (LabeledSales::nbad_index &bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index &bad)
	{
		cout << bad.what();//what()接收bad对象中string &类型
		cout << "bad.index: " << bad.bi_val() << endl;
	}
	cout << "Done!\n";

	system("pause");
	return 0;
}