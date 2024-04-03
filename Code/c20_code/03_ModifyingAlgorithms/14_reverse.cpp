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

	reverse(begin(values), end(values));

	for (const auto& i : values) { cout << i << " "; }
	cout << endl;
}
