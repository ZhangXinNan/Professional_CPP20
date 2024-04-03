import <compare>;
import <iostream>;

using namespace std;

int main()
{
	int i{ 11 };
	strong_ordering result{ i <=> 0 };
	if (is_lt(result)) { cout << "less" << endl; }
	if (is_gt(result)) { cout << "greater" << endl; }
	if (is_eq(result)) { cout << "equal" << endl; }
}