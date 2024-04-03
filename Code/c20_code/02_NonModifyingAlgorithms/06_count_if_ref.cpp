import <vector>;
import <algorithm>;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int value{ 3 };
	int callCounter{ 0 };
	auto tally{ count_if(cbegin(values), cend(values),
		[value, &callCounter](int i) { ++callCounter; return i > value; }) };
	cout << "The lambda expression was called " << callCounter
		<< " times." << endl;
	cout << format("Found {} values > {}.", tally, value) << endl;
}