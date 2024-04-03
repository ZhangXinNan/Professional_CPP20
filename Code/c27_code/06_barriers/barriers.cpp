#include <cstddef>
import <thread>;
import <vector>;
import <stop_token>;
import <barrier>;

using namespace std;

void completionFunction() noexcept { /* ... */ }

// Note: this program will never terminate.
int main()
{
	const size_t numberOfThreads{ 4 };
	barrier barrierPoint{ numberOfThreads, completionFunction };
	vector<jthread> threads;

	for (int i{ 0 }; i < numberOfThreads; ++i) {
		threads.push_back(jthread{ [&barrierPoint](stop_token token) {
			while (!token.stop_requested()) {
				// ... Do some calculations ...

				// Synchronize with other threads.
				barrierPoint.arrive_and_wait();
			}
		} });
	}
}
