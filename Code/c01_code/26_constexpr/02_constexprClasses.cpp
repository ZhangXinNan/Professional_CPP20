#include <cstddef>
import <iostream>;
import <array>;

using namespace std;

class Rect
{
public:
	constexpr Rect(size_t width, size_t height)
		: m_width{ width }, m_height{ height }
	{
	}
	
	constexpr size_t getArea() const
	{
		return m_width * m_height;
	}

private:
	size_t m_width { 0 }, m_height { 0 };
};

int main()
{
	constexpr Rect r{ 8, 2 };
	int myArray[r.getArea()];
	cout << std::size(myArray) << endl;
}