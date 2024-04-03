import <iostream>;
import <format>;

using namespace std;

int main()
{
	try {
		cout << format("An integer: {:.}", 5);
	} catch (const format_error& caught_exception) {
		cout << caught_exception.what(); // "missing precision specifier"
	}
}