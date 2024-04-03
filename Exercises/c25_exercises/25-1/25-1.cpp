import <iostream>;
import <vector>;

using namespace std;

template<typename InputIterator, typename OutputIterator,
	typename Predicate, typename UnaryOperation>
OutputIterator transform_if(InputIterator first, InputIterator last,
	OutputIterator output, Predicate pred, UnaryOperation op)
{
	auto iter{ first };
	while (iter != last) {
		if (pred(*iter)) {
			*output = op(*iter);
		} else {
			*output = *iter;
		}
		++output;
		++iter;
	}
	return output;
}

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto& value : values) { cout << value << " "; }
	cout << endl;

	transform_if(begin(values), end(values), begin(values),
		[](const auto& value) { return value % 2 != 0; },
		[](const auto& value) { return value * 2; });

	for (auto& value : values) { cout << value << " "; }
	cout << endl;
}