#include <cctype>
import <string>;
import <string_view>;
import <iostream>;
import <format>;

using namespace std;

string trim(string_view text)
{
    auto firstNonWhitespace{
        find_if(begin(text), end(text), [](char c) { return !isspace(c); }) };

    // Remember from Chapter 17, to obtain the underlying iterator from a
    // reverse_iterator, you need to call the base() method on the reverse_iterator.
    auto onePassedLastNonWhitespace{
        find_if(rbegin(text), rend(text), [](char c) { return !isspace(c); }).base() };
    
    return { firstNonWhitespace, onePassedLastNonWhitespace };
}

int main()
{
    cout << format("'{}'\n", trim("   Hello World!   "));
    cout << format("'{}'\n", trim("Hello World!   "));
	cout << format("'{}'\n", trim("   Hello World!"));
	cout << format("'{}'\n", trim("Hello World!"));
	cout << format("'{}'\n", trim(" \t Hello World! \n"));
}
