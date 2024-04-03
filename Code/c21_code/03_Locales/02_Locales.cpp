import <iostream>;
import <string>;
import <locale>;

using namespace std;

int main()
{
	locale loc{ "" };

	if (loc.name().find("en_US") == string::npos &&
		loc.name().find("en-US") == string::npos) {
		wcout << L"Welcome non-US English speaker!" << endl;
	} else {
		wcout << L"Welcome US English speaker!" << endl;
	}
}
