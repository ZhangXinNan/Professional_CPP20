#include <cstdlib>
import <iostream>;

[[noreturn]] void forceProgramTermination()
{
	std::exit(1);  // Defined in <cstdlib>
}

bool isDongleAvailable()
{
	bool isAvailable{ false };
	// Check whether a licensing dongle is available...
	return isAvailable;
}

bool isFeatureLicensed(int /*featureId*/)
{
	if (!isDongleAvailable()) {
		// No licensing dongle found, abort program execution!
		forceProgramTermination();
	} else {
		bool isLicensed{ false };
		// Dongle available, perform license check of the given feature...
		return isLicensed;
	}
}

int main()
{
	bool isLicensed{ isFeatureLicensed(42) };
	std::cout << isLicensed << std::endl;
}