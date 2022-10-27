# include <iostream>
# include<string>

int main1()
{
	using namespace std;
	string one("Lottery Winner!");//ctor 1
	cout << one << endl;
	string two(20, '$');//ctor 2
	cout << two << endl;
	string three(one);//ctor 3
	cout << three << endl;
	one += "Oops!";//overloaded+=
	cout << one << endl;
	two = "Sorry! That was ";//reloaded
	three[0] = 'p';
	string four;//default
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);//ctor 5
	cout << five << ",\n";
	string six(alls + 6, alls + 10);//ctor 6
	cout << six << " , ";
	string seven(&five[6], &five[10]);//ctor 6 agin,对象不同于数组，它的名字不能看作指针
	cout << seven << "...\n";
	string eight(four, 7, 16);//ctor 7
	cout << eight << " in motion!" << endl;

	system("pause");
	return 0;

}