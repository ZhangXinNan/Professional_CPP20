#include <cmath>
import <iostream>;
import <chrono>;

using namespace std;
using namespace std::chrono;

int main()
{
	// Get the start time.
	auto start{ high_resolution_clock::now() };
	// Execute code that you want to time.
	double d{ 0 };
	for (int i{ 0 }; i < 1'000'000; ++i) {
		d += sqrt(sin(i) * cos(i));
	}
	// Get the end time and calculate the difference.
	auto end{ high_resolution_clock::now() };
	auto diff{ end - start };
	// Convert the difference into milliseconds and output to the console.
	cout << duration<double, milli>{ diff }.count() << "ms" << endl;
}
