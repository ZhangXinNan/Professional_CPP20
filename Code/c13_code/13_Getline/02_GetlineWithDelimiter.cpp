import <iostream>;
import <string>;
import <format>;

using namespace std;

int main()
{
	cout << "Enter multiple lines of text. "
		<< "Use an @ character to signal the end of the text.\n> ";

	string myString;
	getline(cin, myString, '@');

	cout << format("Read text: \"{}\"", myString) << endl;
}
