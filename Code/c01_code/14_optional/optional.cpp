import <optional>;
import <iostream>;

using namespace std;

optional<int> getData(bool giveIt)
{
	if (giveIt) {
		return 42;
	}

	return nullopt;  // or simply return {};
}

int main()
{
	optional<int> data1{ getData(true) };
	optional<int> data2{ getData(false) };

	cout << "data1.has_value = " << data1.has_value() << endl;
	if (data2) {
		cout << "data2 has a value." << endl;
	}

	cout << "data1.value = " << data1.value() << endl;
	cout << "data1.value = " << *data1 << endl;

	try {
		cout << "data2.value = " << data2.value() << endl;
	} catch (const bad_optional_access& ex) {
		cout << "Exception: " << ex.what() << endl;
	}

	cout << "data2.value = " << data2.value_or(0) << endl;
}
