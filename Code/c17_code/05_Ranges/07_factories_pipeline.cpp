import <string_view>;
import <ranges>;
import <iostream>;

using namespace std;

void printRange(string_view message, auto& range)
{
	cout << message;
	for (const auto& value : range) { cout << value << " "; }
	cout << endl;
}

int main()
{
	auto result{ views::iota(10)
		| views::filter([](const auto& value) {return value % 2 == 0; })
		| views::transform([](const auto& value) {return value * 2.0; })
		| views::take(10) };
	printRange("Result: ", result);
}
