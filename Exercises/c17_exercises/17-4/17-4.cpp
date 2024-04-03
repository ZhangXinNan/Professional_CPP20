import <ranges>;
import <iostream>;
import <vector>;
import <iterator>;

using namespace std;

template <typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
	for (auto iter{ begin }; iter != end; ++iter, ++target) {
		*target = *iter;
	}
}

int main()
{
	cout << "> ";

	// Option 1: using a range-based for loop.
	{
		vector<int> values;

		for (auto& value : ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) {return v != -1; })) {
			values.push_back(value);
		}

		myCopy(begin(values), end(values), ostream_iterator<int> { cout, " "});
	}

	cout << endl << "> ";

	// Option 2: no loop, but using a common view and a vector constructor.
	{
		auto r{ ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) {return v != -1; })
			| views::common };

		vector<int> values(r.begin(), r.end());

		myCopy(begin(values), end(values), ostream_iterator<int> { cout, " "});
	}

	cout << endl << "> ";

	// Option 3: no loop, but using std::ranges::copy() and a back_inserter.
	{
		vector<int> values;

		ranges::copy(ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) { return v != -1; }),
			back_inserter(values));

		myCopy(begin(values), end(values), ostream_iterator<int> { cout, " "});
	}
}
