import <utility>;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	int a{ 11 };
	int b{ 22 };

	cout << format("Before exchange(): a = {}, b = {}", a, b) << endl;

	int returnedValue{ exchange(a, b) };

	cout << format("After exchange():  a = {}, b = {}", a, b) << endl;
	cout << format("exchange() returned: {}", returnedValue) << endl;
}