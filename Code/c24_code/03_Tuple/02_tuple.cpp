import <iostream>;
import <string>;
import <tuple>;
import <functional>;  // for ref() and cref()
import <typeinfo>;
import <format>;

using namespace std;

int main()
{
	using MyTuple = tuple<int, string, bool>;
	MyTuple t1{ 16, "Test", true };
	//tuple t1{ 16, "Test"s, true };  // Using CTAD
	cout << format("t1 = ({}, {}, {})", get<0>(t1), get<1>(t1), get<2>(t1)) << endl;

	cout << "Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;

	cout << "Type of element with index 2 = "
		<< typeid(tuple_element<2, MyTuple>::type).name() << endl;

	cout << "String = " << get<string>(t1) << endl;

	cout << "Tuple Size = " << tuple_size<MyTuple>::value << endl;
	cout << "Tuple Size = " << tuple_size<decltype(t1)>::value << endl;

	double d{ 3.14 };
	string str1{ "Test" };
	// t2 will be tuple<int, double&, const double&, string&>
	tuple t2{ 16, ref(d), cref(d), ref(str1) };  // Using CTAD
	// Or using make_tuple().
	//auto t2{ make_tuple(16, ref(d), cref(d), ref(str1)) };

	cout << "d = " << d << endl;
	get<1>(t2) *= 2;
	//get<2>(t2) *= 2;    // ERROR because of cref().
	cout << "d = " << d << endl;
}