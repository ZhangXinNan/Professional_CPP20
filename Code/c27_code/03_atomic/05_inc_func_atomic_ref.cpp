import <iostream>;
import <vector>;
import <thread>;
import <functional>;
import <chrono>;
import <atomic>;

using namespace std;

void increment(int& counter)
{
	atomic_ref<int> atomicCounter{ counter };
	for (int i{ 0 }; i < 100; ++i) {
		++atomicCounter;
		this_thread::sleep_for(1ms);
	}
}

int main()
{
	int counter{ 0 };
	vector<thread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.push_back(thread{ increment, ref(counter) });
	}

	for (auto& t : threads) {
		t.join();
	}

	cout << "Result = " << counter << endl;
}
