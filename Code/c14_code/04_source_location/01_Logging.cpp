import <iostream>;
import <string_view>;
import <source_location>;
import <format>;

using namespace std;

void logMessage(string_view message,
	const source_location& location = source_location::current())
{
	cout << format("{}({}): {}: {}", location.file_name(),
		location.line(), location.function_name(), message) << endl;
}

void foo()
{
	logMessage("Starting execution of foo().");
}

int main()
{
	foo();
}
