import <string_view>;
import <vector>;
import <ranges>;
import <iostream>;
import <format>;

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

	auto result{ values
		| views::filter([](const auto& value) {return value % 2 == 0; })
		| views::take(3)
		| views::transform([](const auto& v) { return format(R"("{}")", v); }) };
	printRange("Result: ", result);
}
