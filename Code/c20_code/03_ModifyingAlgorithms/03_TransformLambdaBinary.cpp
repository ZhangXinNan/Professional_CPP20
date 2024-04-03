import <algorithm>;
import <iostream>;
import <vector>;

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
	cout << "Vector1:" << endl; populateContainer(vec1);
	cout << "Vector2:" << endl; populateContainer(vec2);

	if (vec2.size() < vec1.size())
	{
		cout << "Vector2 should be at least the same size as vector1." << endl;
		return 1;
	}

	// Create a lambda to print the contents of a container
	auto printContainer{ [](const auto& container) {
		for (auto& i : container) { cout << i << " "; }
		cout << endl;
	} };

	cout << "Vector1: "; printContainer(vec1);
	cout << "Vector2: "; printContainer(vec2);

	transform(begin(vec1), end(vec1), begin(vec2), begin(vec1),
		[](int a, int b){ return a + b; });

	cout << "Vector1: "; printContainer(vec1);
	cout << "Vector2: "; printContainer(vec2);
}
