#include <ctime>
import <iostream>;
import <chrono>;

using namespace std;
using namespace std::chrono;

system_clock::duration getDurationSinceMidnight()
{
	// Get current time.
	auto now{ system_clock::now() };
	
	// From the current time, construct a time representing
	// midnight of the current day.
	time_t nowTimeT{ system_clock::to_time_t(now) };
	tm midnightTm{ 0 };
	localtime_s(&midnightTm, &nowTimeT);
	midnightTm.tm_hour = 0;
	midnightTm.tm_min = 0;
	midnightTm.tm_sec = 0;
	// Construct a time_point for midnight.
	auto midnight{ system_clock::from_time_t(mktime(&midnightTm)) };

	return now - midnight;
}

int main()
{
	auto durationSinceMidnight{ getDurationSinceMidnight() };
	auto numberOfSecondsSinceMidnight{ duration_cast<seconds>(durationSinceMidnight).count() };
	cout << numberOfSecondsSinceMidnight << endl;

	hh_mm_ss hms{ durationSinceMidnight };
	cout << hms.hours().count() << ":" << hms.minutes().count() << ":" << hms.seconds().count() << endl;
}