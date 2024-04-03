import <algorithm>;
import <iostream>;
import <vector>;
import <string_view>;

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

template<typename Iterator>
void DumpRange(string_view message, Iterator begin, Iterator end)
{
	cout << message;
	for_each(begin, end, [](const auto& element) { cout << element << " "; });
	cout << endl;
}

int main()
{
	vector<int> vec1, vec2, result;
	cout << "Enter elements for set 1:" << endl;
	populateContainer(vec1);
	cout << "Enter elements for set 2:" << endl;
	populateContainer(vec2);

	// set algorithms require sorted ranges
	sort(begin(vec1), end(vec1));
	sort(begin(vec2), end(vec2));

	DumpRange("Set 1: ", cbegin(vec1), cend(vec1));
	DumpRange("Set 2: ", cbegin(vec2), cend(vec2));

	if (includes(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2))) {
		cout << "The second set is a subset of the first." << endl;
	}
	if (includes(cbegin(vec2), cend(vec2), cbegin(vec1), cend(vec1))) {
		cout << "The first set is a subset of the second" << endl;
	}

	result.resize(size(vec1) + size(vec2));
	auto newEnd{ set_union(cbegin(vec1), cend(vec1), cbegin(vec2),
		cend(vec2), begin(result)) };
	DumpRange("The union is: ", begin(result), newEnd);

	newEnd = set_intersection(cbegin(vec1), cend(vec1), cbegin(vec2),
		cend(vec2), begin(result));
	DumpRange("The intersection is: ", begin(result), newEnd);

	newEnd = set_difference(cbegin(vec1), cend(vec1), cbegin(vec2),
		cend(vec2), begin(result));
	DumpRange("The difference between set 1 and 2 is: ", begin(result), newEnd);

	newEnd = set_symmetric_difference(cbegin(vec1), cend(vec1),
		cbegin(vec2), cend(vec2), begin(result));
	DumpRange("The symmetric difference is: ", begin(result), newEnd);
}
