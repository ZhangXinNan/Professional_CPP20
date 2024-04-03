import <iostream>;

using namespace std;

int main()
{
	auto sum{ [](auto a, auto b) { return a + b; } };
	cout << sum(11, 22) << endl;
	cout << sum(1.1, 2.2) << endl;
}