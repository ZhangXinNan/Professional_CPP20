#include <ctime>
import <iostream>;
import <random>;
import <algorithm>;
import <functional>;
import <vector>;

using namespace std;

int main()
{
	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	mt19937 engine{ static_cast<mt19937::result_type>(seed) };
	uniform_int_distribution<int> distribution{ 1, 99 };

	auto generator{ bind(distribution, engine) };
	
	vector<int> values(10);
	generate(begin(values), end(values), generator);
	
	for (auto i : values) {
		cout << i << "  ";
	}
	cout << endl;
}

