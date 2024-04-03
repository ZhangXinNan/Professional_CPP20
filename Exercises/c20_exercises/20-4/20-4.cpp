import <vector>;
import <deque>;
import <iostream>;
import <algorithm>;
import <iterator>;
import <numeric>;

using namespace std;

int main()
{
	vector<int> values(100);
	iota(begin(values), end(values), 1);

	deque<int> evens, odds;
	partition_copy(begin(values), end(values),
		back_inserter(evens),
		front_inserter(odds),
		[](int i) { return i % 2 == 0; });

	cout << "Even numbers: ";
	for (const auto& value : evens) { cout << value << " "; }
	cout << "\nOdd numbers: ";
	for (const auto& value : odds) { cout << value << " "; }
}