import <iostream>;
import <vector>;
import <thread>;
import <functional>;
import <chrono>;
import <atomic>;

using namespace std;

void increment(atomic<int>& counter)
{
	int result{ 0 };
	for (int i{ 0 }; i < 100; ++i) {
		++result;
		this_thread::sleep_for(1ms);
	}
	counter += result;
}

int main()
{
	atomic<int> counter{ 0 };
	vector<thread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.push_back(thread{ increment, ref(counter) });
	}

	for (auto& t : threads) {
		t.join();
	}

	cout << "Result = " << counter << endl;
}
