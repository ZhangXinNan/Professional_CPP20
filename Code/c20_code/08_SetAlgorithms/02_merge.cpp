import <algorithm>;
import <vector>;
import <iostream>;
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
	vector<int> vectorOne, vectorTwo, vectorMerged;
	cout << "Enter values for first vector:" << endl;
	populateContainer(vectorOne);
	cout << "Enter values for second vector:" << endl;
	populateContainer(vectorTwo);

	// Sort both containers
	sort(begin(vectorOne), end(vectorOne));
	sort(begin(vectorTwo), end(vectorTwo));

	// Make sure the destination vector is large enough to hold the values
	// from both source vectors.
	vectorMerged.resize(size(vectorOne) + size(vectorTwo));

	merge(cbegin(vectorOne), cend(vectorOne), cbegin(vectorTwo),
		cend(vectorTwo), begin(vectorMerged));

	DumpRange("Merged vector: ", cbegin(vectorMerged), cend(vectorMerged));
}
