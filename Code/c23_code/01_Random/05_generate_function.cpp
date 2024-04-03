#include <ctime>
import <iostream>;
import <random>;
import <algorithm>;
import <functional>;
import <vector>;

using namespace std;

// Using C++20 abbreviated function template syntax.
void fillVector(vector<int>& values, const auto& generator)
{
	generate(begin(values), end(values), generator);
}

//template<typename T>
//void fillVector(vector<int>& values, const T& generator)
//{
//	generate(begin(values), end(values), generator);
//}

//void fillVector(vector<int>& values, const function<int()>& generator)
//{
//	generate(begin(values), end(values), generator);
//}

int main()
{
	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	mt19937 engine{ static_cast<mt19937::result_type>(seed) };
	uniform_int_distribution<int> distribution{ 1, 99 };

	auto generator{ bind(distribution, engine) };

	vector<int> values(10);
	fillVector(values, generator);

	for (auto i : values) {
		cout << i << "  ";
	}
	cout << endl;
}

