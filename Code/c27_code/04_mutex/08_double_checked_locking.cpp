import <iostream>;
import <thread>;
import <mutex>;
import <vector>;
import <atomic>;

using namespace std;

void initializeSharedResources()
{
	// ... Initialize shared resources to be used by multiple threads.

	cout << "Shared resources initialized." << endl;
}

atomic<bool> g_initialized{ false };
mutex g_mutex;

void processingFunction()
{
	if (!g_initialized) {
		unique_lock lock{ g_mutex };
		if (!g_initialized) {
			initializeSharedResources();
			g_initialized = true;
		}
	}
	cout << "OK" << endl;
}

int main()
{
	vector<thread> threads;

	for (int i{ 0 }; i < 5; ++i) {
		threads.push_back(thread{ processingFunction });
	}

	for (auto& t : threads) {
		t.join();
	}
}
