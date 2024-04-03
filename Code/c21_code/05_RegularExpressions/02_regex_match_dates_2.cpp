import <iostream>;
import <string>;
import <regex>;
import <format>;

using namespace std;

int main()
{
	regex r{ "(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])" };
	while (true) {
		cout << "Enter a date (year/month/day) (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (smatch m; regex_match(str, m, r)) {
			int year{ stoi(m[1]) };
			int month{ stoi(m[2]) };
			int day{ stoi(m[3]) };
			cout << format("  Valid date: Year={}, month={}, day={}", year, month, day) << endl;
		} else {
			cout << "  Invalid date!" << endl;
		}
	}
}