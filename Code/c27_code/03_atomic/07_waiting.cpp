import <thread>;
import <atomic>;
import <iostream>;
import <chrono>;

using namespace std;

int main()
{
	atomic<int> value{ 0 };

	thread job{ [&value] {
		cout << "Thread starts waiting." << endl;
		value.wait(0);
		cout << "Thread wakes up, value = " << value << endl;
	} };

	this_thread::sleep_for(2s);

	cout << "Main thread is going to change value to 1." << endl;
	value = 1;
	value.notify_all();

	job.join();
}