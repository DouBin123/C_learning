# include <iostream>
# include <string>
# include <set>
# include <algorithm>
# include <iterator>

int main12()
{
	using namespace std;
	const int N = 6;
	string s1[N] = { "buffoon", "thinker", "for", "heavy", "can", "for" };
	string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };

	set<string>A(s1, s1 + N );
	set<string>B(s2, s2 + N);

	ostream_iterator<string, char>out(cout, " ");//向输出流(ostream)中添加元素,这里是向cout中添加，要读取的数据类型为string,输出方式类型为char,
	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "Set B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;
	cout << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "Intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "Differece of A and B:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	cout << "Set C:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "Set C after insertion:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "Showing a range:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("speak"), out);//首字母的上下限 g-s
	cout << endl;

	system("pause");
	return 0;
}