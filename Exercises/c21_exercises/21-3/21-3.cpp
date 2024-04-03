import <iostream>;
import <string>;
import <regex>;

using namespace std;

int main()
{
	regex r{ "^(.*?)//.*$" };
	const string replacement{ "$1" };
	while (true) {
		cout << "Enter a source code snippet, terminated with @:" << endl;
		string str;
		if (!getline(cin, str, '@')) {
			break;
		}

		cout << regex_replace(str, r, replacement) << endl;
	}
}