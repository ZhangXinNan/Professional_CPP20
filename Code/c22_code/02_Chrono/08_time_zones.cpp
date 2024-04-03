import <chrono>;
import <iostream>;

using namespace std;
using namespace std::chrono;

int main()
{
	// List all time zones in the database.
	const auto& database{ get_tzdb() };
	for (const auto& timezone : database.zones) {
		cout << timezone.name() << endl;
	}

	// Create some time zones.
	auto* brussels{ locate_zone("Europe/Brussels") };
	auto* gmt{ locate_zone("GMT") };
	auto* current{ current_zone() };

	// Convert the current time from your time zone to GMT.
	gmt->to_local(system_clock::now());

	// Construct a UTC time.
	auto t{ sys_days{ 2020y / June / 22d } + 9h + 35min + 10s }; // 2020-06-22 09:35:10 UTC
	// Convert UTC time to Brussels' local time.
	brussels->to_local(t);

	// Construct a local time in the Brussels' time zone.
	zoned_time<hours> brusselsTime{ brussels, local_days { 2020y / June / 22d } + 9h };
	// Convert to New York time.
	zoned_time<hours> newYorkTime{ "America/New_York", brusselsTime };
}