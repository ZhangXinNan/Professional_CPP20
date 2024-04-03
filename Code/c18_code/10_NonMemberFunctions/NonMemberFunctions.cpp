import <vector>;
import <iostream>;

using namespace std;

int main()
{
	vector vec{ 1, 2, 3 };
	cout << size(vec) << endl;
	cout << empty(vec) << endl;

	auto s1{ size(vec) };   // Type is size_t (unsigned)
	auto s2{ ssize(vec) };  // Type is long long (signed)
}
