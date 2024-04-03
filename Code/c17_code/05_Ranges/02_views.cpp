import <string_view>;
import <vector>;
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
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printRange("Original sequence: ", values);

	// Filter out all odd values, leaving only the even values.
	auto result1{ values | views::filter([](const auto& value) { return value % 2 == 0; }) };
	//Or:
	//  auto result1{ ranges::filter_view{ values, [](const auto& value) { return value % 2 == 0; } } };
	printRange("Only even values: ", result1);

	// Transform all values to their double value.
	auto result2{ result1 | views::transform([](const auto& value) { return value * 2.0; }) };
	printRange("Values doubled: ", result2);

	// Drop the first 2 elements.
	auto result3{ result2 | views::drop(2) };
	printRange("First two dropped: ", result3);

	// Reverse the view.
	auto result4{ result3 | views::reverse };
	printRange("Sequence reversed: ", result4);
}
