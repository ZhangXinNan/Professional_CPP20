import <iostream>;
import <string>;
import <tuple>;

using namespace std;

template <typename TupleType, int n>
class TuplePrint
{
public:
	TuplePrint(const TupleType& t) {
		TuplePrint<TupleType, n - 1> tp{ t };
		cout << get<n - 1>(t) << endl;
	}
};

template <typename TupleType>
class TuplePrint<TupleType, 0>
{
public:
	TuplePrint(const TupleType&) { }
};

int main()
{
	using MyTuple = tuple<int, string, bool>;
	MyTuple t1{ 16, "Test", true };
	TuplePrint<MyTuple, tuple_size<MyTuple>::value> tp{ t1 };
}
