import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: m_id{ id }, m_numIterations{ numIterations }
	{
	}

	void operator()() const
	{
		for (int i{ 0 }; i < m_numIterations; ++i) {
			unique_lock lock{ ms_timedMutex, 200ms };
			if (lock) {
				cout << "Counter " << m_id << " has value " << i << endl;
			} else {
				// Lock not acquired in 200ms, skip output.
			}
		}
	}

private:
	int m_id;
	int m_numIterations;
	inline static timed_mutex ms_timedMutex;
};

int main()
{
	// Using uniform initialization syntax
	thread t1{ Counter{ 1, 20 } };

	// Using named variable
	Counter c{ 2, 12 };
	thread t2{ c };

	// Wait for threads to finish
	t1.join();
	t2.join();
}
