import <iostream>;
import <array>;
import <format>;

using namespace std;

int main()
{
	array<int, 3> arr{ 9, 8, 7 };
	// array arr{ 9, 8, 7 };  // Using CTAD
	cout << format("Array size = {}", arr.size()) << endl;
	cout << format("2nd element = {}", arr[1]) << endl;
}
