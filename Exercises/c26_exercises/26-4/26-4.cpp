import <iostream>;
import <vector>;
import <string>;

using namespace std;

template<typename T, typename... Args>
void push_back_values(vector<T>& values, Args&&... args)
{
	(values.push_back(std::forward<Args>(args)), ...);
}

int main()
{
	vector<int> values1;
	push_back_values(values1, 9, 8, 7, 6);
	for (auto& value : values1) { cout << value << " "; }
	cout << endl;

	vector<double> values2;
	push_back_values(values2, 1.1, 2, 3.3, 4);
	for (auto& value : values2) { cout << value << " "; }
	cout << endl;

	vector<string> values3;
	push_back_values(values3, "Hello", "World", "!");
	for (auto& value : values3) { cout << value << " "; }
	cout << endl;
}