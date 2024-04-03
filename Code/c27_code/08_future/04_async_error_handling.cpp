import <iostream>;
import <future>;
import <exception>;
import <stdexcept>;

using namespace std;

int calculate()
{
	throw runtime_error{ "Exception thrown from calculate()." };
}

int main()
{
	// Use the launch::async policy to force asynchronous execution.
	auto myFuture{ async(launch::async, calculate) };

	// Do some more work...

	// Get the result.
	try {
		int result{ myFuture.get() };
		cout << result << endl;
	} catch (const exception& ex) {
		cout << "Caught exception: " << ex.what() << endl;
	}
}
