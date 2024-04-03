import <iostream>;
import <stdexcept>;

using namespace std;

void g()
{
	throw invalid_argument{ "Some exception" };
}

void f()
{
	try {
		g();
	} catch (const invalid_argument& e) {
		cout << "caught in f: " << e.what() << endl;
		throw;  // rethrow
	}
}

int main()
{
	try {
		f();
	} catch (const invalid_argument& e) {
		cout << "caught in main: " << e.what() << endl;
	}
}