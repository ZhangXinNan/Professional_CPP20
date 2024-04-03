import <ranges>;
import <iostream>;
import <string>;

using namespace std;

int main()
{
	auto result{ views::iota(10, 100)
		| views::transform([](const auto& v) { return v * v; })
		| views::filter([](const auto& v) { return v % 5 != 0; })
		| views::transform([](const auto& v) { return to_string(v); }) };

	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
}
