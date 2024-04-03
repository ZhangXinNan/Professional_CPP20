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

	while (true) {
		cout << "Enter a number to find (0 to quit): ";
		int number;
		cin >> number;
		if (number == 0) {
			break;
		}
		if (binary_search(cbegin(values), cend(values), number)) {
			cout << "That number is in the vector." << endl;
		} else {
			cout << "That number is not in the vector." << endl;
		}
	}
}
