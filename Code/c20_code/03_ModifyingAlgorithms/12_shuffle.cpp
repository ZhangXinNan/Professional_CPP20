#include <ctime>
import <algorithm>;
import <vector>;
import <iostream>;
import <random>;

using namespace std;

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	default_random_engine engine{ static_cast<default_random_engine::result_type>(seed) };

	for (int i{ 0 }; i < 6; ++i) {
		shuffle(begin(values), end(values), engine);

		for (const auto& value : values) { cout << value << " "; }
		cout << endl;
	}
}
