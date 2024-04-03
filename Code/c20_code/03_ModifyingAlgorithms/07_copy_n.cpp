#include <cstddef>
import <algorithm>;
import <vector>;
import <iostream>;

using namespace std;

// Function template to populate a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
	while (true) {
		cout << "Enter a number (0 to quit): ";
		int value;
		cin >> value;
		if (value == 0) {
			break;
		}
		cont.push_back(value);
	}
}

int main()
{
	vector<int> vec1, vec2;

	populateContainer(vec1);

	size_t tally{ 0 };
	cout << "Enter number of elements you want to copy: ";
	cin >> tally;
	tally = min(tally, size(vec1));
	vec2.resize(tally);
	copy_n(cbegin(vec1), tally, begin(vec2));
	for (const auto& i : vec2) { cout << i << " "; }

	cout << endl;
}
