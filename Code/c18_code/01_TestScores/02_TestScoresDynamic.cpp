#include <cstddef>
import <vector>;
import <iostream>;
import <limits>;
import <format>;

using namespace std;

int main()
{
	vector<double> doubleVector; // Create a vector with zero elements.

	// Initialize max to smallest number
	double max{ -numeric_limits<double>::infinity() };

	for (size_t i{ 1 }; true; i++) {
		double temp;
		cout << format("Enter score {} (-1 to stop): ", i);
		cin >> temp;
		if (temp == -1) {
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max) {
			max = temp;
		}
	}

	max /= 100.0;
	for (auto& element : doubleVector) {
		element /= max;
		cout << element << " ";
	}
	cout << endl;
}
