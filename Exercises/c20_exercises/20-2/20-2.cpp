import <vector>;
import <iostream>;
import <algorithm>;

using namespace std;

int main()
{
	vector<int> values;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		int number;
		cin >> number;
		if (number == 0) {
			break;
		}
		values.push_back(number);
	}

	// The permutation algorithms require the sequence to be sorted.
	sort(begin(values), end(values));

	// Helper lambda expression to print values.
	auto print{ [&values] {
		for (const auto& value : values) {
			cout << value << " ";
		}
		cout << endl;
	} };

	// Print initial sorted sequence.
	print();

	// Loop over all permutations.
	while (next_permutation(begin(values), end(values))) {
		print();
	}
}