import <vector>;
import <iostream>;

using namespace std;

template<typename T>
void printVector(const vector<T>& v)
{
	for (auto& element : v) { cout << element << " "; }
	cout << endl;
}

int main()
{
	vector values{ 1, 2, 3, 2, 1, 2, 4, 5 };
	printVector(values);

	erase(values, 2);
	printVector(values);
}
