#include <cstddef>
import <thread>;
import <vector>;
import <iostream>;
import <atomic>;
import <format>;
import <functional>;

using namespace std;

atomic_flag spinlock = ATOMIC_FLAG_INIT; // Uniform initialization is not allowed.
static const size_t NumberOfThreads{ 50 };
static const size_t LoopsPerThread{ 100 };

void dowork(size_t threadNumber, vector<size_t>& data)
{
	for (size_t i{ 0 }; i < LoopsPerThread; ++i) {
		while (spinlock.test_and_set()) {}  // Spins until lock is acquired.
		// Save to handle shared data...
		data.push_back(threadNumber);
		spinlock.clear();                    // Releases the acquired lock.
	}
}

int main()
{
	vector<size_t> data;
	vector<thread> threads;
	for (size_t i{ 0 }; i < NumberOfThreads; ++i) {
		threads.push_back(thread{ dowork, i, ref(data) });
	}
	for (auto& t : threads) {
		t.join();
	}
	cout << format("data contains {} elements, expected {}.\n", data.size(),
		NumberOfThreads * LoopsPerThread);
}
