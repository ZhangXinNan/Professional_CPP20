import <iostream>;
import <array>;

using namespace std;

int main()
{
	array<int, 3> myArray{ 11, 22, 33 };
	cout << std::get<1>(myArray) << endl;
	// cout << std::get<10>(myArray) << endl;  // BUG! Compilation error!
}