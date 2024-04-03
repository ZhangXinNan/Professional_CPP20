import <array>;
import <utility>;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	{
		// Structured bindings with std::array.
		std::array values{ 11, 22, 33 };
		auto [x, y, z] { values };
	}

	{
		// Structured bindings with struct.
		struct Point { double m_x, m_y, m_z; };
		Point point;
		point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
		auto [x, y, z] { point };
	}

	{
		// Structured bindings with std::pair.
		pair myPair{ "hello", 5 };
		auto [theString, theInt] { myPair };  // Decompose using structured bindings
		cout << format("theString: {}", theString) << endl;
		cout << format("theInt: {}", theInt) << endl;
	}
}
