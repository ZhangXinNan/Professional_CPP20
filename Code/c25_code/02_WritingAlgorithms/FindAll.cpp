import <vector>;
import <iostream>;
import <iterator>;
import <format>;

using namespace std;

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator find_all(InputIterator first, InputIterator last,
	OutputIterator dest, Predicate pred)
{
	while (first != last) {
		if (pred(*first)) {
			*dest = first;
			++dest;
		}
		++first;
	}
	return dest;
}


int main()
{
	vector vec{ 3, 4, 5, 4, 5, 6, 5, 8 };
	vector<vector<int>::iterator> matches;

	find_all(begin(vec), end(vec), back_inserter(matches), [](int i){ return i == 5; });

	cout << format("Found {} matching elements: ", matches.size()) << endl;

	for (const auto& it : matches) {
		cout << format("{} at position {}", *it, distance(begin(vec), it)) << endl;
	}
	cout << endl;
}
