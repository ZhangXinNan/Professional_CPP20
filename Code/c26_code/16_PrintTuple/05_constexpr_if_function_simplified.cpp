import <iostream>;
import <string>;
import <tuple>;

using namespace std;

template <typename TupleType, int n = tuple_size<TupleType>::value>
void tuplePrint(const TupleType& t) {
	if constexpr (n > 1) {
		tuplePrint<TupleType, n - 1>(t);
	}
	cout << get<n - 1>(t) << endl;
}

int main()
{
	tuple t1{ 167, "Testing"s, false, 2.3 };
	tuplePrint(t1);
}
