import <iostream>;
import <string>;
import <tuple>;
import <format>;

using namespace std;

int main()
{
	tuple t1{ 16, "Test"s, true };  // Using CTAD
	// Or:
	//tuple<int, string, bool> t1{ 16, "Test", true };

	{
		int i{ 0 };
		string str;
		bool b{ false };
		cout << format("Before: i = {}, str = \"{}\", b = {}", i, str, b) << endl;
		tie(i, str, b) = t1;
		cout << format("After: i = {}, str = \"{}\", b = {}", i, str, b) << endl;
	}

	{
		int i{ 0 };
		bool b{ false };
		cout << format("Before: i = {}, b = {}", i, b) << endl;
		tie(i, ignore, b) = t1;
		cout << format("After: i = {}, b = {}", i, b) << endl;
	}
}