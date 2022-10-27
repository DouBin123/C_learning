//capacity()and reserve()
# include <iostream>
# include <string>
 
int main4()
{
	using namespace std;
	string empty;
	string small = "bit";
	string large = "Elephants are a girl's best friend";
	cout << "Sizes:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsamll: " << small.size() << endl;
	cout << "\tlarge: " << large.size() << endl;
	cout << "Capcities: \n";
	
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsamll: " << small.capacity() << endl;
	cout << "\tlarge: " << large.capacity() << endl;
	empty.reserve(50);
	cout << "Capcity after empty.reserve(50): "
		<< empty.capacity() << endl;
	system("pause");
	return 0;
}