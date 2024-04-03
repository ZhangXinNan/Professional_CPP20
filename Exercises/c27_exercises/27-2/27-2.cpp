import <iostream>;
import <chrono>;
import <thread>;
import <stop_token>;

using namespace std;
using namespace std::chrono;

void beeper(stop_token token, duration<int> delay)
{
	while (!token.stop_requested()) {
		cout << '\a';
		this_thread::sleep_for(delay);
	}
}

int main()
{
	auto beepThread{ jthread{ beeper, 3s } };
	
	cout << "Press enter to stop beeping";
	cin.ignore();

	beepThread.request_stop();
}
