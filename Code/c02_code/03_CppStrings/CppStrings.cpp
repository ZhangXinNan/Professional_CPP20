import <string>;
import <iostream>;
import <compare>;

using namespace std;

int main()
{
	{
		string a{ "12" };
		string b{ "34" };
		string c;
		c = a + b;    // c is "1234"
		cout << c << endl;

		a += b;    // a is "1234"
		cout << a << endl;
	}

	{
		string a{ "12" };
		string b{ "34" };

		auto result{ a.compare(b) };
		if (result < 0) { cout << "less" << endl; }
		if (result > 0) { cout << "greater" << endl; }
		if (result == 0) { cout << "equal" << endl; }
	}

	{
		// C++20 three-way comparison operator
		string a{ "12" };
		string b{ "34" };
		auto result{ a <=> b };
		if (is_lt(result)) { cout << "less" << endl; }
		if (is_gt(result)) { cout << "greater" << endl; }
		if (is_eq(result)) { cout << "equal" << endl; }
	}

	{
		string myString{ "hello" };

		myString += ", there";

		string myOtherString{ myString };

		if (myString == myOtherString) {
			myOtherString[0] = 'H';
		}

		cout << myString << endl;
		cout << myOtherString << endl;
	}

	{
		string strHello{ "Hello!!" };
		string strWorld{ "The World..." };
		auto position{ strHello.find("!!") };
		if (position != string::npos) {
			// Found the "!!" substring, now replace it.
			strHello.replace(position, 2, strWorld.substr(3, 6));
		}
		cout << strHello << endl;
	}

	{
		auto string1{ "Hello World" };    // string1 is a const char*.
		auto string2{ "Hello World"s };   // string2 is an std::string.
	}
}
