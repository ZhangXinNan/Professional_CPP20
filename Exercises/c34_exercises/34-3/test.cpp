#include "reverseString.h"
import <iostream>;
import <string_view>;
import <string>;

using namespace std;

// A wrapper class for the C reverseString library.
class ReverseString
{
public:
	ReverseString(string_view s)
	{
		char* reversedString{ reverseString(const_cast<char*>(s.data())) };
		m_reversedString = reversedString;
		freeString(reversedString);
	}

	const string& getReversedString() const
	{
		return m_reversedString;
	}

private:
	string m_reversedString;
};



int main()
{
	ReverseString reverser{ "Hello World!" };

	cout << reverser.getReversedString() << endl;
}