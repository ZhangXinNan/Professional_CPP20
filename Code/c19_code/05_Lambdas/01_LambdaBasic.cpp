import <iostream>;
import <string>;

using namespace std;

class Person
{
public:
	Person(std::string name) : m_name{ std::move(name) } { }
	const std::string& getName() const { return m_name; }

private:
	std::string m_name;
};

int main()
{
	// Basic lambda
	auto basicLambda{ [] { cout << "Hello from Lambda" << endl; } };
	basicLambda();

	// Lambda with parameters
	auto parametersLambda{ [](int value) { cout << "The value is " << value << endl; } };
	parametersLambda(42);

	// Lambda returning a value
	auto returningLambda{ [](int a, int b) -> int { return a + b; } };
	int sum{ returningLambda(11, 22) };
	cout << "The result is " << sum << endl;

	// Lambda returning a value, with return type omitted
	auto returningLambda2{ [](int a, int b) { return a + b; } };
	sum = returningLambda2(11, 22);
	cout << "The result is " << sum << endl;

	// Demonstrating stripping of reference and const qualifiers
	Person p{ "John Doe" };
	decltype(auto) name1{ [](const Person& person) { return person.getName(); }(p) };
	decltype(auto) name2{ [](const Person& person) -> decltype(auto) { return person.getName(); }(p) };

	// Lambda capturing a variable by value
	double data{ 1.23 };
	auto capturingVLambda{ [data] { cout << "Data = " << data << endl; } };
	capturingVLambda();

	// Lambda capturing a variable by value
	auto capturingVLambda2{ [data]() mutable { data *= 2; cout << "Data = " << data << endl; } };
	capturingVLambda2();

	// Lambda capturing a variable by reference
	auto capturingRLambda{ [&data] { data *= 2; } };
	capturingRLambda();
	cout << "Data = " << data << endl;
}
