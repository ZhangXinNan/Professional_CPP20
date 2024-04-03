import <algorithm>;
import <vector>;
import <iostream>;

using namespace std;

int main()
{
	vector<int> myVector;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		int number;
		cin >> number;
		if (number == 0) {
			break;
		}
		myVector.push_back(number);
	}

	while (true) {
		cout << "Enter a number to lookup (0 to stop): ";
		int number;
		cin >> number;
		if (number == 0) {
			break;
		}
		auto endIt{ cend(myVector) };
		//auto it{ find(cbegin(myVector), endIt, number) };
		//if (it == endIt) {
		if (auto it{ find(cbegin(myVector), endIt, number) }; it == endIt) {
			cout << "Could not find " << number << endl;
		} else {
			cout << "Found " << *it << endl;
		}
	}
}
