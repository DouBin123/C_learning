//truncate.cpp---using get() to truncate(截断) input line,if necessary
# include <iostream>
const int SLEN = 10;
inline void eatline() { while (std:: cin.get() != '\n')continue; }//continue 会删除该行中余下的内容
int main12()
{
	using namespace std;
	char name[SLEN];
	char title[SLEN];
	cout << "Enter your name: ";
	cin.get(name, SLEN);
	if (cin.peek() != '\n')
		cout << "Sorry,we only have enough room for" << name << endl;
	eatline();
	cout << " Dear " << name << " , enter your title:\n";
	cin.get(title, SLEN);
	if (cin.peek()!='\n')
	{
		cout << "We were forced to truncate your title.\n";
	}
	eatline();
	cout << " Name: " << name << "\nTitle: " << title << endl;

	system("pause");
	return 0;
}