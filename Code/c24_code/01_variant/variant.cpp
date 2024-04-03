import <variant>;
import <string>;
import <iostream>;

using namespace std;

class MyVisitor
{
public:
	void operator()(int i) { cout << "int " << i << endl; }
	void operator()(const string& s) { cout << "string " << s << endl; }
	void operator()(float f) { cout << "float " << f << endl; }
};

int main()
{
	variant<int, string, float> v;
	v = 12;
	v = 12.5f;
	v = "An std::string"s;

	cout << "Type index: " << v.index() << endl;
	cout << "Contains an int: " << holds_alternative<int>(v) << endl;

	cout << get<string>(v) << endl;
	try {
		cout << get<0>(v) << endl;
	} catch (const bad_variant_access& ex) {
		cout << "Exception: " << ex.what() << endl;
	}

	string* theString{ get_if<string>(&v) };
	int* theInt{ get_if<int>(&v) };
	cout << "Retrieved string: " << (theString ? *theString : "null") << endl;
	cout << "Retrieved int: " << (theInt ? *theInt : 0) << endl;

	visit(MyVisitor{}, v);
}
