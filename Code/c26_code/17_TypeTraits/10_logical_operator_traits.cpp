import <type_traits>;
import <iostream>;

using namespace std;

int main()
{
	cout << conjunction_v<is_integral<int>, is_integral<short>> << " ";
	cout << conjunction_v<is_integral<int>, is_integral<double>> << " ";

	cout << disjunction_v<is_integral<int>, is_integral<double>, is_integral<short>> << " ";

	cout << negation_v<is_integral<int>> << " ";
}
