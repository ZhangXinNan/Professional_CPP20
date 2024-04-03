import <thread>;
import <iostream>;
import <mutex>;
import <vector>;

using namespace std;

once_flag g_onceFlag;

void initializeSharedResources()
{
	// ... Initialize shared resources to be used by multiple threads.

	cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
	// Make sure the shared resources are initialized.
	call_once(g_onceFlag, initializeSharedResources);

	// ... Do some work, including using the shared resources
	cout << "Processing" << endl;
}

int main()
{
	// Launch 3 threads.
	vector<thread> threads{ 3 };
	for (auto& t : threads) {
		t = thread{ processingFunction };
	}

	// Join on all threads
	for (auto& t : threads) {
		t.join();
	}
}
