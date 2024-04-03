import <vector>;
import <algorithm>;
import <iostream>;

using namespace std;

int main()
{
	vector<int> values(10); // Create a vector of 10 elements.
	int value{ 1 };
	generate(begin(values), end(values), [&value]{ value *= 2; return value; });
	for (const auto& i : values) {
		cout << i << " ";
	}
	cout << endl;
}
