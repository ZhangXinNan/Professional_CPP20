import <thread>;
import <iostream>;
import <format>;

using namespace std;

int k;
thread_local int n;

void threadFunction(int id)
{
	cout << format("Thread {}: k={}, n={}\n", id, k, n);
	++n;
	++k;
}

int main()
{
	thread t1{ threadFunction, 1 };
	t1.join();

	thread t2{ threadFunction, 2 };
	t2.join();
}