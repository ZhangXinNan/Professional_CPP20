#include <ctime>
import <iostream>;
import <random>;
import <functional>;
import <format>;

using namespace std;

auto createDiceValueGenerator()
{
	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	mt19937 engine{ static_cast<mt19937::result_type>(seed) };
	shuffle_order_engine<mt19937, 15> shuffledEngine{ engine };
	uniform_int_distribution<int> distribution{ 1, 6 };
	return bind(distribution, shuffledEngine);
}

int main()
{
	auto generator{ createDiceValueGenerator() };

	while (true)
	{
		cout << "Throw two dice? (y or n): ";
		char answer;
		cin >> answer;
		if (answer == 'n' || answer == 'N') {
			break;
		}

		auto dieValue1{ generator() };
		auto dieValue2{ generator() };
		cout << format("{} & {}\n", dieValue1, dieValue2);
	}
}

