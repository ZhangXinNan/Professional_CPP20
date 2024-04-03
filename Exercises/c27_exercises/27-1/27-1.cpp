import <iostream>;
import <chrono>;
import <thread>;

using namespace std;
using namespace std::chrono;

void beeper(duration<int> delay)
{
	while (true) {
		cout << '\a';
		this_thread::sleep_for(delay);
	}
}

int main()
{
	auto beepThread{ thread{ beeper, 3s } };
	beepThread.join();
}