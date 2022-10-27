# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

using namespace std;
const int NUM = 10;
const string wordlist[NUM] = { "apple", "better", "cry",
					"danger", "sad", "good", "make", "tie", "mabe", "the"
							};
int main3()
{
	srand(time(0));
	char play;
	cout << "Will you play a word game?<y/n>" << endl;
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[rand() % NUM];//枚举用enum_name(n)
		int length = target.length();
		string attemp(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word.It has " << length << " letters, and you guess\n"
			<< " one letter at a time. you get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attemp << endl;
		while (guesses > 0 && attemp != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attemp.find(letter) != string::npos)
			{
				cout << "Your already guessed that. Try agin.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh ,bad guess!\n";
				--guesses;
				badchars += letter;//将之前的
			}
			else
			{
				cout << "Good guess!\n";
				attemp[loc] = letter;
				//check if letter appears agin
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attemp[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			//之前是程序内部判断，后面是程序显示
			cout << "Your word: " << attemp << endl;
			if (attemp != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses>0)
		{
			cout << "That's right!\n";
		}
		else
		
			cout << "Sorry, the word is " << target << endl;
		cout << "Will you play another? <y/n> ";
				cin >> play;
			play = tolower(play);
	
	}
	cout << "Bye.\n";


	system("pause");
	return 0;
}