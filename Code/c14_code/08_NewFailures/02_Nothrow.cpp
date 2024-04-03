#include <cstddef>
import <iostream>;
import <limits>;
import <format>;
import <source_location>;

using namespace std;

int main()
{
	size_t integerCount{ numeric_limits<size_t>::max() };
	cout << format("Trying to allocate memory for {} integers.", integerCount) << endl;

	int* ptr{ new(nothrow) int[integerCount] };
	if (ptr == nullptr) {
		auto location{ source_location::current() };
		cerr << format("{}({}): Unable to allocate memory!",
			location.file_name(), location.line()) << endl;
		// Handle memory allocation failure.
		return 1;
	}
	// Proceed with function that assumes memory has been allocated.
}
