import <thread>;
import <iostream>;

using namespace std;

int main()
{
	int id{ 1 };
	int numIterations{ 5 };
	thread t1{ [id, numIterations] {
		for (int i{ 0 }; i < numIterations; ++i) {
			cout << "Counter " << id << " has value " << i << endl;
		}
	} };
	t1.join();
}
