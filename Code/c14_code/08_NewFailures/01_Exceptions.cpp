#include <cstddef>
import <iostream>;
import <limits>;
import <format>;
import <source_location>;

using namespace std;

int main()
{
	int* ptr{ nullptr };
	size_t integerCount{ numeric_limits<size_t>::max() };
	cout << format("Trying to allocate memory for {} integers.", integerCount) << endl;

	try {
		ptr = new int[integerCount];
	} catch (const bad_alloc& e) {
		auto location{ source_location::current() };
		cerr << format("{}({}): Unable to allocate memory: {}",
			location.file_name(), location.line(), e.what()) << endl;
		// Handle memory allocation failure.
		return 1;
	}
	// Proceed with function that assumes memory has been allocated.
}
