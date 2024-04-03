import <iostream>;
import <vector>;
import <algorithm>;

using namespace std;

int main()
{
	vector values{ 1, 2, 3 };
	auto result1{ ranges::find(cbegin(values), cend(values), 2) };
	if (result1 != cend(values)) {
		cout << *result1 << endl;
	}

	auto result2{ ranges::find(values, 2) };
	if (result2 != cend(values)) {
		cout << *result2 << endl;
	}
}