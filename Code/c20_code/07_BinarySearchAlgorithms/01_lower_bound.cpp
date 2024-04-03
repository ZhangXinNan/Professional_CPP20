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
	vector<int> values;
	populateContainer(values);

	// Sort the container
	sort(begin(values), end(values));

	cout << "Sorted vector: ";
	for (const auto& i : values) { cout << i << " "; }
	cout << endl;

	while (true) {
		int number;
		cout << "Enter a number to insert (0 to quit): ";
		cin >> number;
		if (number == 0) {
			break;
		}
		
		auto iter{ lower_bound(begin(values), end(values), number) };
		values.insert(iter, number);
		
		cout << "New vector: ";
		for (const auto& i : values) { cout << i << " "; }
		cout << endl;
	}
}
