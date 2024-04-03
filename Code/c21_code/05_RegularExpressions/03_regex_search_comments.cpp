import <iostream>;
import <string>;
import <regex>;
import <format>;

using namespace std;

int main()
{
	regex r{ "//\\s*(.+)$" };
	while (true) {
		cout << "Enter a string with optional code comments (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (smatch m; regex_search(str, m, r)) {
			cout << format("  Found comment '{}'", m[1].str()) << endl;
		} else {
			cout << "  No comment found!" << endl;
		}
	}
}
