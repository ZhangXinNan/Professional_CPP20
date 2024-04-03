import <iostream>;
import <string>;
import <tuple>;
import <format>;

using namespace std;

int main()
{
	tuple t1{ 16, "Test"s, true };   // Using CTAD
	// Or:
	//tuple<int, string, bool> t1{ 16, "Test", true };

	auto [i, str, b] { t1 };
	cout << format("Decomposed: i = {}, str = \"{}\", b = {}", i, str, b) << endl;

	auto& [i2, str2, b2] { t1 };
	i2 *= 2;
	str2 = "Hello World";
	b2 = !b2;
}