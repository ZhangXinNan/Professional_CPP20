import <iostream>;
import <initializer_list>;

using namespace std;

int makeSum(initializer_list<int> values)
{
	int total{ 0 };
	for (int value : values) {
		total += value;
	}
	return total;
}

int main()
{
	int a{ makeSum({ 1, 2, 3 }) };
	int b{ makeSum({ 10, 20, 30, 40, 50, 60 }) };

	cout << a << endl;
	cout << b << endl;
}
