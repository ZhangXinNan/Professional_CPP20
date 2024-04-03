#include <cstddef>
#include <cstdlib>
import <new>;
import <iostream>;
import <limits>;
import <format>;
import <source_location>;

using namespace std;

class please_terminate_me : public bad_alloc { };

void myNewHandler()
{
	cerr << "Unable to allocate memory." << endl;
	throw please_terminate_me{};
}

int main()
{
	try {
		// Set the new new_handler and save the old one.
		new_handler oldHandler{ set_new_handler(myNewHandler) };

		// Generate allocation error.
		size_t numInts{ numeric_limits<size_t>::max() };
		int* ptr{ new int[numInts] };

		// Reset the old new_handler.
		set_new_handler(oldHandler);
	} catch (const please_terminate_me&) {
		auto location{ source_location::current() };
		cerr << format("{}({}): Terminating program.",
			location.file_name(), location.line()) << endl;
		return 1;
	}
}
