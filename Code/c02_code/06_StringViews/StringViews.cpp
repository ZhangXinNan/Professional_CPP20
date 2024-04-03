#include <cstddef>
import <iostream>;
import <string>;
import <string_view>;
import <format>;

using namespace std;

string_view extractExtension(string_view filename)
{
	return filename.substr(filename.rfind('.'));
}

void handleExtension(const string& extension) { /* ... */ }

int main()
{
	// C++ std::string.
	string filename{ R"(c:\temp\my file.ext)" };
	cout << format("C++ string: {}", extractExtension(filename)) << endl;

	// C-style string.
	const char* cString{ R"(c:\temp\my file.ext)" };
	cout << format("C string: {}", extractExtension(cString)) << endl;

	// String literal.
	cout << format("Literal: {}", extractExtension(R"(c:\temp\my file.ext)")) << endl;

	// Raw string buffer with given length.
	const char* raw{ "test.ext" };
	size_t length{ 8 };
	cout << format("Raw: {}", extractExtension({ raw, length })) << endl;
	cout << format("Raw: {}", extractExtension(string_view{ raw, length })) << endl;

	// Assigning the result to a std::string.
	string extension{ extractExtension(filename).data() };

	handleExtension(extractExtension("my file.ext").data());    // data() method
	handleExtension(string{ extractExtension("my file.ext") }); // explicit ctor

	// Concatenation with string_view.
	string str{ "Hello" };
	string_view sv{ " world" };
	//auto result{ str + sv };  // Error, does not compile.
	auto result1{ str + sv.data() };
	string result2{ str };
	result2.append(sv.data(), sv.size());
}
