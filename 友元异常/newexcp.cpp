# include <iostream>
# include <new>
# include <cstdlib>//for exit()
using namespace std;

struct Big
{
	double stuff[2000];
};
 
int main8()
{
	Big *pb;//a pointer to structor
	try{
		cout << "Try to get a big block of memory:\n";
		pb = new Big[1000];//1000��structor
		cout << "Got past the new requst:\n";
	}
	catch (bad_alloc &ba)
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[]pb;

	system("pause");
	return 0;

}