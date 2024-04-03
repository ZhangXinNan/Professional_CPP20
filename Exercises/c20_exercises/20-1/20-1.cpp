import <vector>;
import <iostream>;
import <algorithm>;

using namespace std;

int main()
{
	cout << "Enter a number: ";
	int number;
	cin >> number;

	vector<int> values(10);
	fill(begin(values), end(values), number);
	
	for (const auto& value : values) {
		cout << value << " ";
	}
	cout << endl;
}