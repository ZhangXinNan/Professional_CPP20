import <compare>;
import <iostream>;

using namespace std;

int main()
{
	int i{ 11 };
	strong_ordering result{ i <=> 0 };
	if (result == strong_ordering::less) { cout << "less" << endl; }
	if (result == strong_ordering::greater) { cout << "greater" << endl; }
	if (result == strong_ordering::equal) { cout << "equal" << endl; }
}