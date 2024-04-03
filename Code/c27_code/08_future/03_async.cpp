import <iostream>;
import <future>;

using namespace std;

int calculate()
{
	return 123;
}

int main()
{
	auto myFuture{ async(calculate) };
	//auto myFuture{ async(launch::async, calculate) };
	//auto myFuture{ async(launch::deferred, calculate) };

	// Do some more work...

	// Get the result.
	int result{ myFuture.get() };
	cout << result << endl;
}
