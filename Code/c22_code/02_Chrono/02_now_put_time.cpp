#include <ctime>
import <iostream>;
import <chrono>;
import <iomanip>;

using namespace std;
using namespace std::chrono;

int main()
{
	// Get current time as a time_point.
	system_clock::time_point tpoint{ system_clock::now() };

	// Convert to a time_t.
	time_t tt{ system_clock::to_time_t(tpoint) };

	// Convert to local time.
	tm* t{ localtime(&tt) };
	// Write the time to the console.
	cout << put_time(t, "%H:%M:%S") << endl;

	// You might get a security-related error or warning on the call to localtime() above.
	// With Microsoft Visual C++ you should use the safe version called localtime_s(),
	// while on Linux you should use localtime_r().
	// For example, for Visual C++ you can implement the above as follows:
	//// Convert to local time.
	//tm t;
	//localtime_s(&t, &tt);
	//// Write the time to the console
	//cout << put_time(&t, "%H:%M:%S") << endl;
}
