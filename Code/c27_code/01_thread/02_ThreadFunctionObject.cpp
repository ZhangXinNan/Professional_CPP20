import <thread>;
import <iostream>;

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
			cout << "Counter " << m_id << " has value " << i << endl;
		}
	}

private:
	int m_id;
	int m_numIterations;
};

int main()
{
	// Using uniform initialization syntax.
	thread t1{ Counter{ 1, 20 } };

	// Using named variable.
	Counter c{ 2, 12 };
	thread t2{ c };

	// Wait for threads to finish.
	t1.join();
	t2.join();
}
