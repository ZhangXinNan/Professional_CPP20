import <thread>;
import <vector>;
import <semaphore>;

using namespace std;

int main()
{
	counting_semaphore semaphore{ 4 };

	vector<jthread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.push_back(jthread{ [&semaphore] {
			semaphore.acquire();
			// ... Slot acquired ... (at most 4 threads concurrently)
			semaphore.release();
		} });
	}

	// No need to manually call join(), as we are using C++20 jthread.
}
