import <iostream>;
import <exception>;
import <stdexcept>;
import <string>;
import <format>;

using namespace std;

class MyException : public exception
{
public:
	MyException(string message) : m_message{ move(message) } {}
	const char* what() const noexcept override { return m_message.c_str(); }

private:
	string m_message;
};


void doSomething()
{
	try {
		throw runtime_error{ "Throwing a runtime_error exception" };
	} catch (const runtime_error& /*e*/) {
		cout << format("{} caught a runtime_error", __func__) << endl;
		cout << format("{} throwing MyException", __func__) << endl;
		throw_with_nested(MyException{ "MyException with nested runtime_error" });
	}
}

int main()
{
	try {
		doSomething();
	} catch (const MyException& e) {
		cout << format("{} caught MyException: {}", __func__, e.what()) << endl;
/*
		const auto* nested{ dynamic_cast<const nested_exception*>(&e) };
		if (nested) {
			try {
				nested->rethrow_nested();
			} catch (const runtime_error& e) {
				// Handle nested exception.
				cout << format("  Nested exception: {}", e.what()) << endl;
			}
		}
*/
		try {
			rethrow_if_nested(e);
		} catch (const runtime_error& e) {
			// Handle nested exception.
			cout << format("  Nested exception: {}", e.what()) << endl;
		}
	}
}
