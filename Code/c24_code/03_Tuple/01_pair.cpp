import <iostream>;
import <string>;
import <utility>;
import <format>;

using namespace std;

int main()
{
	pair<int, string> p1{ 16, "Hello World" };
	pair p2{ true, 0.123f };
	cout << format("p1 = ({}, {})", p1.first, p1.second) << endl;
	cout << format("p2 = ({}, {})", p2.first, p2.second) << endl;
}
