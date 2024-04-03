import <algorithm>;
import <iostream>;
import <vector>;
import <execution>;

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
	vector<int> myVector;
	populateContainer(myVector);

	cout << "Before sorting:" << endl;
	for (const auto& i : myVector) { cout << i << " "; }
	cout << endl;

	sort(execution::par, begin(myVector), end(myVector));

	cout << "After sorting:" << endl;
	for (const auto& i : myVector) { cout << i << " "; }
	cout << endl;
}
