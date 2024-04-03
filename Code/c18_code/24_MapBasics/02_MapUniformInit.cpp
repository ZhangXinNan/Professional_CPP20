import <iostream>;
import <map>;
import <string>;
import <format>;

using namespace std;

int main()
{
	map<string, int> m{
		{ "Marc G.", 123 },
		{ "Warren B.", 456 },
		{ "Peter V.W.", 789 }
	};

	for (const auto& p : m) {
		cout << format("{} = {}", p.first, p.second) << endl;
	}
}
