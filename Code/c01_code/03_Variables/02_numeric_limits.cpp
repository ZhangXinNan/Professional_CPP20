import <iostream>;
import <limits>;
import <format>;

using namespace std;

int main()
{
	cout << "int:\n";
	cout << format("Max int value: {}\n", numeric_limits<int>::max());
	cout << format("Min int value: {}\n", numeric_limits<int>::min());
	cout << format("Lowest int value: {}\n", numeric_limits<int>::lowest());

	cout << "\ndouble:\n";
	cout << format("Max double value: {}\n", numeric_limits<double>::max());
	cout << format("Min double value: {}\n", numeric_limits<double>::min());
	cout << format("Lowest double value: {}\n", numeric_limits<double>::lowest());
}