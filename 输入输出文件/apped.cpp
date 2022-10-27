//append.cpp--appending information to a file
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

const char* files = "guest.txt";
int main14()
{
	using namespace std;
	char ch;
	//show initial contents
	ifstream fin(files);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< files << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	//add new names
	ofstream fout(files, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << files << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names(enter a blank line to quit):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	//show revised file 
	fin.clear();
	fin.open(files);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< files << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "Done!\n";
	system("pause");
	return 0;
}