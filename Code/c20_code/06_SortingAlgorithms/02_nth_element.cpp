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
	cout << "Enter at least five values." << endl;
	
	vector<int> values;
	populateContainer(values);
	// Find the third largest value.
	nth_element(begin(values), begin(values) + 2, end(values), greater<>{});
	cout << "3rd largest value: " << values[2] << endl;


	// Get the 5 largest elements in sorted order.
	nth_element(begin(values), begin(values) + 4, end(values), greater<>{});
	// nth_element() has partitioned the elements, now sort the first subrange.
	sort(begin(values), begin(values) + 5);
	// And finally, output the sorted subrange.
	for_each_n(begin(values), 5, [](const auto& element) { cout << element << "  "; });
}
