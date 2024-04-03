import <iostream>;
import <string>;
import <regex>;

using namespace std;

int main()
{
	regex r{ "(?=(?:.*\\d){2})(?=.*[[:lower:]])(?=.*[[:upper:]])(?=.*[[:punct:]]).{8,}" };
	while (true) {
		cout << "Enter a password (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (regex_match(str, r)) {
			cout << "  Valid password." << endl;
		} else {
			cout << "  Invalid password!" << endl;
		}
	}
}