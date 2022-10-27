# include <iostream>
# include <string>
# include<vector>
# include <algorithm>
using namespace std;

struct Review
{
	string  title;
	int rating;
};

bool operator<(const Review &r1, const Review &r2);
bool worseThan(const Review &r1, const Review &r2);
bool FillReview1(Review &rr);
void ShowReview1(Review &rr);

int main9()
{

	vector<Review> books;
	Review temp;
	while (FillReview1(temp))
	{
		books.push_back(temp);
	}
	if (books.size() > 0)
	{
		cout << "Thank you. you entered the following:"
			<< books.size() << "ratings:\n"
			<< "Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview1);
		sort(books.begin(), books.end());
		cout << "sorted by title:\nRating\tBook\n";
		vector<Review>::iterator pr;
		for_each(pr = books.begin(), books.end(), ShowReview1);
		sort(books.begin(), books.end(), worseThan);
		cout << "sorted by rating:\nRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview1);
		for (auto x : books)ShowReview1(x);

		random_shuffle(books.begin(), books.end());
		cout << "After shuffling:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview1);
	}
	else
		cout << "No entries.";
	cout << "Bye.\n";
	system("pause");
	return 0;
}
bool operator<(const Review &r1, const Review &r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title&&r1.rating < r2.rating)
		return true;
	else
		return false;

}
bool worseThan(const Review &r1, const Review &r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}


bool FillReview1(Review &rr)
{
	cout << "Enter book title(quit to quit): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr.rating;
	if (!cin)
		return false;
	//get rid of rest ofinput line
	while (cin.get() != '\n')
		continue;
	return true;
}
void ShowReview1(Review &rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}