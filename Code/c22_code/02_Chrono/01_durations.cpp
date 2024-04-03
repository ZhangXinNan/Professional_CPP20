import <iostream>;
import <chrono>;
import <format>;

using namespace std;
using namespace std::chrono;

int main()
{
	// Specify a duration where each tick is 60 seconds.
	duration<long, ratio<60>> d1{ 123 };
	cout << d1.count() << endl;

	// Specify a duration represented by a double with each tick
	// equal to 1 second and assign the largest possible duration to it.
	auto d2{ duration<double>::max() };
	cout << d2.count() << endl;

	// Define 2 durations:
	// For the first duration, each tick is 1 minute.
	// For the second duration, each tick is 1 second.
	duration<long, ratio<60>> d3{ 10 };  // = 10 minutes
	duration<long, ratio<1>> d4{ 14 };   // = 14 seconds

	// Compare both durations.
	if (d3 > d4) { cout << "d3 > d4" << endl; }
	else { cout << "d3 <= d4" << endl; }

	// Increment d4 with 1 resulting in 15 seconds.
	++d4;

	// Multiply d4 by 2 resulting in 30 seconds.
	d4 *= 2;

	// Add both durations and store as minutes.
	duration<double, ratio<60>> d5{ d3 + d4 };

	// Add both durations and store as seconds.
	duration<long, ratio<1>> d6{ d3 + d4 };
	cout << format("{} minutes + {} seconds = {} minutes or {} seconds",
		d3.count(), d4.count(), d5.count(), d6.count()) << endl;

	// Create a duration of 30 seconds.
	duration<long> d7{ 30 };

	// Convert the seconds of d7 to minutes.
	duration<double, ratio<60>> d8{ d7 };
	cout << format("{} seconds = {} minutes", d7.count(), d8.count()) << endl;

	// Convert the seconds of d7 to integral minutes using duration_cast().
	auto d8_{ duration_cast<duration<long, ratio<60>>>(d7) };    // minutes
	cout << d8_.count() << endl;

	// Convert integral minutes to integral seconds.
	duration<long, ratio<60>> d9{ 10 };    // minutes
	//minutes d9{ 10 };                    // minutes
	duration<long> d10{ d9 };              // seconds
	cout << d10.count() << endl;

	// Use predefined durations.
	auto t{ hours{ 1 } + minutes{ 23 } + seconds{ 45 } };
	cout << format("{} seconds", seconds{ t }.count()) << endl;

	// Standard user-defined literals.
	auto myDuration{ 42min };    // 42 minutes
}
