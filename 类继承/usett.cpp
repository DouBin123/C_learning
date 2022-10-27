# include <iostream>
# include"tabtenn.h"

int main()
{
	using namespace std;
	TableTennisPlayer player1("Chunk", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << " :has a table.\n";
	else
		cout << " :hasn't a table.\n";
	player2.Name();
	if (player2.HasTable())
		cout << " :has a table.\n";
	else
		cout << " :hasn't a table.\n";
	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; Rating: " << rplayer2.Rating() << endl;
	system("pause");
	return 0;
}