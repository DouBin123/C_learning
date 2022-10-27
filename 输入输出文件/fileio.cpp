//fileio.cpp--saving to a file
# include <iostream>
# include <fstream>
# include <string>

int main13()
{
	using namespace std;
	string filename;

	cout << "Enter name for new file: ";
	cin >> filename;

	//create output stream object for newfilr and call it fout
	ofstream fout(filename.c_str());

	fout << "For your eyes only!\n";//write to file
	cout << "Enter your secert number£º";//write to screen
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();

	//create input stream object for new file and call if fin
	ifstream fin(filename.c_str());
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))
		cout << ch;
	cout << "Done\n";
	fin.close();

	system("pause");
	return 0;
}