import <iostream>;
import <string>;
import <regex>;
import <format>;

using namespace std;

int main()
{
	regex reg{ R"(\s*[,;]\s*)" };
	while (true) {
		cout << "Enter a string to split on ',' and ';' (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}
		
		const sregex_token_iterator end;
		for (sregex_token_iterator iter{ cbegin(str), cend(str), reg, -1 };
			iter != end; ++iter) {
			cout << format("\"{}\"", iter->str()) << endl;
		}
	}
}