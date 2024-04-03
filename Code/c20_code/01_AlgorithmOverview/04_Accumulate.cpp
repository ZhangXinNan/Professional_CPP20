#include <cmath>
import <numeric>;
import <vector>;
import <iostream>;
import <span>;
import <functional>;

using namespace std;

double arithmeticMean(span<const int> values)
{
	double sum{ accumulate(cbegin(values), cend(values), 0.0) };
	return sum / values.size();
}

int product(int value1, int value2)
{
	return value1 * value2;
}

double geometricMean(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1, product) };
	return pow(mult, 1.0 / values.size());
}

double geometricMeanLambda(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1,
		[](int value1, int value2) { return value1 * value2; }) };
	return pow(mult, 1.0 / values.size());
}

double geometricMeanFunctor(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1, multiplies<>{}) };
	return pow(mult, 1.0 / values.size());
}

int main()
{
	vector<int> myVector;

	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		int score;
		cin >> score;
		if (score == 0) {
			break;
		}
		myVector.push_back(score);
	}

	cout << "The arithmetic mean is " << arithmeticMean(myVector) << endl;
	cout << "The geometric mean is " << geometricMean(myVector) << endl;
	cout << "The geometric mean (Lambda version) is " << geometricMeanLambda(myVector) << endl;
	cout << "The geometric mean (multiplies<>) is " << geometricMeanFunctor(myVector) << endl;
}
