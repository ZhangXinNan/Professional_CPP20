import logger;
import <iostream>;
import <thread>;
import <vector>;
import <format>;

using namespace std;

void logSomeMessages(int id, Logger& logger)
{
	for (int i{ 0 }; i < 10; ++i) {
		logger.log(format("Log entry {} from thread {}", i, id));
	}
}

int main()
{
	Logger logger;

	vector<thread> threads;
	// Create a few threads all working with the same Logger instance.
	for (int i{ 0 }; i < 10; ++i) {
		threads.emplace_back(logSomeMessages, i, ref(logger));
		// The above is equivalent to:
		// threads.push_back(thread{ logSomeMessages, i, ref(logger) });
	}

	// Wait for all threads to finish.
	for (auto& t : threads) {
		t.join();
	}
}
