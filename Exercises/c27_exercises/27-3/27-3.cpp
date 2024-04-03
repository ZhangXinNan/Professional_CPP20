import <iostream>;
import <chrono>;
import <thread>;
import <atomic>;

using namespace std;
using namespace std::chrono;

atomic<bool> isBeepingEnabled{ true };

void beeper(duration<int> delay)
{
	while (true) {
		if (isBeepingEnabled) {
			cout << '\a';
		}
		this_thread::sleep_for(delay);
	}
}

int main()
{
	auto beepThread{ thread{ beeper, 3s } };
	
	while (true) {
		cout << "Press enter to pause beeping";
		cin.ignore();
		isBeepingEnabled = !isBeepingEnabled;

		cout << "Press enter to resume beeping";
		cin.ignore();
		isBeepingEnabled = !isBeepingEnabled;
	}

	
	beepThread.join();
}