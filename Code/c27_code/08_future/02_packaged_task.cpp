import <iostream>;
import <thread>;
import <future>;

using namespace std;

int calculateSum(int a, int b)
{
	return a + b;
}

int main()
{
	// Create a packaged task to run calculateSum.
	packaged_task<int(int, int)> task{ calculateSum };
	// Get the future for the result of the packaged task.
	auto theFuture{ task.get_future() };
	// Create a thread, move the packaged task into, and
	// execute the packaged task with the given arguments.
	thread theThread{ move(task), 39, 3 };
	
	// Do some more work...

	// Get the result.
	int result{ theFuture.get() };
	cout << result << endl;

	// Make sure to join the thread.
	theThread.join();
}
