import <string>;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	string myString{ "Hello, World" };
	cout << format("The value of myString is {}", myString) << endl;
	cout << format("The second letter is {}", myString[1]) << endl;
}
