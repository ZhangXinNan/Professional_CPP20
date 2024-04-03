import <vector>;
import <numeric>;
import <iostream>;

using namespace std;

int main()
{
	vector<int> values(10);
	iota(begin(values), end(values), 5);
	for (auto& i : values) { cout << i << " "; }
	cout << endl;
}