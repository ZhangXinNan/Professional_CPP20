import <functional>;
import <iostream>;
import <string_view>;
import <string>;

using namespace std;

void printMessage(string_view message)
{
	cout << message << endl;
}

int main()
{
	invoke(printMessage, "Hello invoke.");
	invoke([](const auto& msg) { cout << msg << endl; }, "Hello invoke.");
	string msg{ "Hello invoke." };
	cout << invoke(&string::size, msg) << endl;
}
