import <iostream>;
import <string>;
import <format>;

using namespace std;

int main()
{
	{
		// width
		int i{ 42 };
		cout << format("|{:5}|", i) << endl;      // |   42|
		cout << format("|{:{}}|", i, 7) << endl;  // |     42|
	}

	cout << endl;

	{
		// [fill]align
		int i{ 42 };
		cout << format("|{:7}|", i) << endl;    // |     42|
		cout << format("|{:<7}|", i) << endl;   // |42     |
		cout << format("|{:_>7}|", i) << endl;  // |_____42|
		cout << format("|{:_^7}|", i) << endl;  // |__42___|
	}

	cout << endl;

	{
		// sign
		int i{ 42 };
		cout << format("|{:<5}|", i) << endl;   // |42   |
		cout << format("|{:<+5}|", i) << endl;  // |+42  |
		cout << format("|{:< 5}|", i) << endl;  // | 42  |
		cout << format("|{:< 5}|", -i) << endl; // |-42  |
	}

	cout << endl;

	{
		// Integral types
		int i{ 42 };
		cout << format("|{:10d}|", i) << endl;   // |        42|
		cout << format("|{:10b}|", i) << endl;   // |    101010|
		cout << format("|{:#10b}|", i) << endl;  // |  0b101010|
		cout << format("|{:10X}|", i) << endl;   // |        2A|
		cout << format("|{:#10X}|", i) << endl;  // |      0X2A|
	}

	cout << endl;

	{
		// String types
		string s{ "ProCpp" };
		cout << format("|{:_^10}|", s) << endl; // |__ProCpp__|
	}

	cout << endl;

	{
		// Floating-point types
		double d{ 3.1415 / 2.3 };
		cout << format("|{:12g}|", d) << endl;                         // |    1.365870|
		cout << format("|{:12.2}|", d) << endl;                        // |        1.37|
		cout << format("|{:12e}|", d) << endl;                         // |1.365870e+00|

		int width{ 12 };
		int precision{ 3 };
		cout << format("|{2:{0}.{1}f}|", width, precision, d) << endl; // |       1.366|
	}

	cout << endl;

	{
		// 0
		int i{ 42 };
		cout << format("|{:06d}|", i) << endl;   // |000042|
		cout << format("|{:+06d}|", i) << endl;  // |+00042|
		cout << format("|{:06X}|", i) << endl;   // |00002A|
		cout << format("|{:#06X}|", i) << endl;  // |0X002A|
	}
}
