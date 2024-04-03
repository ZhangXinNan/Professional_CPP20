import <iostream>;
import <thread>;

using namespace std;

void counter(int id, int numIterations)
{
	for (int i{ 0 }; i < numIterations; ++i) {
		cout << "Counter " << id << " has value " << i << endl;
	}
}

int main()
{
	thread t1{ counter, 1, 6 };
	thread t2{ counter, 2, 4 };
	t1.join();
	t2.join();
}
