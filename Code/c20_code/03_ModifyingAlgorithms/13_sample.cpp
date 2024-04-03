#include <cstddef>
#include <ctime>
import <algorithm>;
import <vector>;
import <iostream>;
import <random>;

using namespace std;

int main()
{
	vector values{ 1,2,3,4,5,6,7,8,9,10 };
	const size_t numberOfSamples{ 5 };
	vector<int> samples(numberOfSamples);

	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	default_random_engine engine{ static_cast<default_random_engine::result_type>(seed) };

	for (int i{ 0 }; i < 6; ++i) {
		sample(cbegin(values), cend(values), begin(samples), numberOfSamples, engine);

		for (const auto& sample : samples) { cout << sample << " "; }
		cout << endl;
	}
}
