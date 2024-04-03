#include <cstddef>
import <iostream>;
import <string>;
import <format>;

using namespace std;

int main()
{
	const string toParse{ "   123USD" };
	size_t index{ 0 };
	int value{ stoi(toParse, &index) };
	cout << format("Parsed value: {}", value) << endl;
	cout << format("First non-parsed character: '{}'", toParse[index]) << endl;
}