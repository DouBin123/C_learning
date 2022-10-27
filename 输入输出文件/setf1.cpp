//setf1.cpp-----uisng  setf() to control formatting
# include <iostream>

int main5()
{
	using namespace std;
	int temperature = 63;
	cout << "Today 's water temperature: ";
	cout.setf(ios_base::showpos);//show plus sign
	cout << temperature << endl;

	cout << "For pur programming friends,that;s \n";
	cout <<  hex << temperature << endl;
	cout.setf(ios_base::uppercase);//using uppercase in hex
	cout.setf(ios_base::showbase);//use 0x prefix for hex
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << " !  oops---How ";//TRUE显示为1
	cout.setf(ios_base::boolalpha);
	cout << true << "!\n";//ture显示为ture


	system("pause");
	return 0;
}