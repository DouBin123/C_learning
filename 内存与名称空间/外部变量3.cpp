# include <iostream>
using namespace std;
double warming = 0.3;
void update(double dt);
void local();
int main3()
{
	cout << "Global warming is " << warming << " degreea.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degreea.\n";
	local();
	cout << "Global warming is " << warming << " degreea.\n";
	system("pause");
	return 0;
}