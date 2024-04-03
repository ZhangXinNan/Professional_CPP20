import <iostream>;
import <string>;
import <regex>;

using namespace std;

int main()
{
	regex reg{ "([\\w]+)" };
	const string replacement{ "$1\n" };
	while (true) {
		cout << "Enter a string to split over multiple lines (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}
		
		cout << regex_replace(str, reg, replacement, regex_constants::format_no_copy) << endl;
	}
}
