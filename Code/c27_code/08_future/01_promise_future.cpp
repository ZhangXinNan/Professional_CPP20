import <iostream>;
import <thread>;
import <future>;

using namespace std;

void doWork(promise<int> thePromise)
{
	// ... Do some work ...
	// And ultimately store the result in the promise.
	thePromise.set_value(42);
}

int main()
{
	// Create a promise to pass to the thread.
	promise<int> myPromise;
	// Get the future of the promise.
	auto theFuture{ myPromise.get_future() };
	// Create a thread and move the promise into it.
	thread theThread{ doWork, move(myPromise) };

	// Do some more work...

	// Get the result.
	int result{ theFuture.get() };
	cout << "Result: " << result << endl;

	// Make sure to join the thread.
	theThread.join();
}
