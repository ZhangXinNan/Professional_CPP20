import <iostream>;
import <string>;
import <regex>;
import <format>;

using namespace std;

int main()
{
	regex reg{ "[\\w]+" };
	while (true) {
		cout << "Enter a string to split (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}
		
		const sregex_iterator end;
		for (sregex_iterator iter{ cbegin(str), cend(str), reg }; iter != end; ++iter) {
			cout << format("\"{}\"", (*iter)[0].str()) << endl;
		}
	}
}