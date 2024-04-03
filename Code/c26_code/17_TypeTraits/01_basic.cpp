import <iostream>;
import <string>;
import <type_traits>;

using namespace std;

int main()
{
	if (is_integral<int>::value) {
		cout << "int is integral" << endl;
	} else {
		cout << "int is not integral" << endl;
	}

	if (is_class<string>::value) {
		cout << "string is a class" << endl;
	} else {
		cout << "string is not a class" << endl;
	}

	// Using C++17 _v helpers.
	if (is_integral_v<int>) {
		cout << "int is integral" << endl;
	} else {
		cout << "int is not integral" << endl;
	}

	if (is_class_v<string>) {
		cout << "string is a class" << endl;
	} else {
		cout << "string is not a class" << endl;
	}
}
