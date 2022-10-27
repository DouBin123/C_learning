# include <iostream>
# include"dma.h"
int main()
{
	using namespace std;
	baseDMA shirt("Portabelly", 8);//construction
	lacksDMA ballon("red", "Buffalo", 4);
	hasDMA map("Mercattor", "Blimppo", 5);

	cout << "Displaying baseDMA object: \n";
	cout << shirt<<endl;;
	cout << "Displaying lacksDMA object: \n";
	cout << ballon << endl;;
	cout << "Displaying hasDMA object: \n";
	cout << map;
	lacksDMA balloon2(ballon);//copy construction of baseDMA
	cout << "result of lacksDMA copy: \n";
	cout << balloon2<<endl;;
	hasDMA map2;
	map2 = map;//operator=£¨£© constructor of hasDMA
	cout << "result of hasDMA assignment: \n";
	cout << map2 << endl;;



	system("pause");
	return 0;

}