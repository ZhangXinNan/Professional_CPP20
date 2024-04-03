import <chrono>;
import <iostream>;

using namespace std;
using namespace std::chrono;

int main()
{
	auto utcTime{ sys_days{ 2020y / June / 22d } + 9h + 35min + 10s };

	zoned_time<seconds> tokyoTime{ "Asia/Tokyo", utcTime };
	zoned_time<seconds> newYorkTime{ "America/New_York", tokyoTime };
	zoned_time<seconds> gmtTime{ "GMT", newYorkTime };

	cout << utcTime << endl;
	cout << gmtTime << endl;
}
