import <iostream>;
import <string>;
import <regex>;
import <chrono>;

using namespace std;
using namespace std::chrono;

int main()
{
	regex r{ "(\\d{4})-(\\d{2})-(\\d{2})" };
	while (true) {
		cout << "Enter a date (yyyy-mm-dd) (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (smatch m; regex_match(str, m, r)) {
			cout << "  Parsed date, now validating..." << endl;
			year_month_day date{ year(stoi(m[1])),
				month(stoi(m[2])),
				day(stoi(m[3])) };
			cout << "    date is " <<
				(date.ok() ? "valid." : "not valid!") << endl;
		} else {
			cout << "  Cannot parse date!" << endl;
		}
	}
}
