import <iostream>;
import <string>;
import <regex>;
import <format>;

using namespace std;

int main()
{
	regex r{ "(\\d{3})-(\\d{3})-(\\d{4})" };
	while (true) {
		cout << "Enter a US phone number (xxx-xxx-xxxx) (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (smatch m; regex_match(str, m, r)) {
			cout << "  Valid phone number:" << endl;
			cout << format("{}\n{}\n{}\n", m[1].str(), m[2].str(), m[3].str());
		} else {
			cout << "  Invalid phone number!" << endl;
		}
	}
}