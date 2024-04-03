import <chrono>;
import <iostream>;
import <format>;

using namespace std;
using namespace std::chrono;

int main()
{
	seconds d1{ 42 };
	duration<double, ratio<60>> d2{ 1.5 };
	auto d3{ d1 + d2 };
	cout << format("{} seconds or {} minutes.",
		d3.count(),
		duration<double, ratio<60>>{ d3 }.count()) << endl;
}