import <iostream>;
import <exception>;
import <stdexcept>;
import <format>;

using namespace std;

class SubObject
{
	public:
		SubObject(int i)
		{
			throw runtime_error{ "Exception by SubObject ctor" };
		}
};

class MyClass
{
	public:
		MyClass();
	private:
		int* m_data{ nullptr };
		SubObject m_subObject;
};

MyClass::MyClass()
try
	: m_data{ new int[42]{ 1, 2, 3 } }, m_subObject{ 42 }
{
	/* ... constructor body ... */
}
catch (const exception& e)
{
	// Cleanup memory.
	delete[] m_data;
	m_data = nullptr;
	cout << format("function-try-block caught: '{}'", e.what()) << endl;
}

int main()
{
	try {
		MyClass m;
	} catch (const exception& e) {
		cout << format("main() caught: '{}'", e.what()) << endl;
	}
}
