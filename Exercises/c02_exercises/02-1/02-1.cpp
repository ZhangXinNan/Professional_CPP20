import <iostream>;
import <string>;
import <compare>;

using namespace std;

int main()
{
	// Ask a first string.
	string s1;
	getline(cin, s1);

	// Ask a second string.
	string s2;
	getline(cin, s2);

	// Print the strings in alphabetical order using <=>.
	if (is_lt(s1 <=> s2)) {
		cout << s1 << endl << s2 << endl;
	} else {
		cout << s2 << endl << s1 << endl;
	}
}
