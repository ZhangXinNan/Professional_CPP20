#include <cmath>
import <iostream>;
import <vector>;
import <functional>;

using namespace std;

template<typename Iter, typename StartValue, typename Operation>
auto accumulateData(Iter begin, Iter end, StartValue startValue, Operation op)
{
	auto accumulated{ startValue };
	for (Iter iter{ begin }; iter != end; ++iter) {
		accumulated = op(accumulated, *iter);
	}
	return accumulated;
}

bool allTrue(const vector<bool>& flags)
{
	return accumulateData(begin(flags), end(flags), true, logical_and<>{});			// C++14 transparent function object
	//return accumulateData(begin(flags), end(flags), true, logical_and<bool>{});	// Pre-C++14
}

bool anyTrue(const vector<bool>& flags)
{
	return accumulateData(begin(flags), end(flags), false, logical_or<>{});			// C++14 transparent function object
	//return accumulateData(begin(flags), end(flags), false, logical_or<bool>{});	// Pre-C++14
}

int main()
{
	vector<bool> myVector;
	while (true) {
		cout << "Enter a value 0 or 1 to add (-1 to stop): ";
		int value;
		cin >> value;
		if (value == -1) {
			break;
		}
		myVector.push_back(value == 1);
	}

	cout << "allTrue? " << (allTrue(myVector) ? "yes" : "no") << endl;
	cout << "anyTrue? " << (anyTrue(myVector) ? "yes" : "no") << endl;
}
