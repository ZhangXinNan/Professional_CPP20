import <ranges>;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	for (auto value : ranges::istream_view<int>(cin)
		| views::take_while([](const auto& v) { return v < 5; })
		| views::transform([](const auto& v) { return v * 2; })) {
		cout << format("> {}\n", value);
	}
	cout << "Terminating..." << endl;
}
