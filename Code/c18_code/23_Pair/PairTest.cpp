import <utility>;
import <string>;
import <iostream>;

using namespace std;

int main()
{
	// Two-argument constructor and default constructor
	pair<string, int> myPair{ "hello", 5 };
	pair<string, int> myOtherPair;

	// Can assign directly to first and second
	myOtherPair.first = "hello";
	myOtherPair.second = 6;

	// copy constructor
	pair<string, int> myThirdPair{ myOtherPair };

	// operator<
	if (myPair < myOtherPair) {
		cout << "myPair is less than myOtherPair" << endl;
	} else {
		cout << "myPair is greater than or equal to myOtherPair" << endl;
	}

	// operator==
	if (myOtherPair == myThirdPair) {
		cout << "myOtherPair is equal to myThirdPair" << endl;
	} else {
		cout << "myOtherPair is not equal to myThirdPair" << endl;
	}

	pair<int, double> pair1{ make_pair(5, 10.10) };
	auto pair2{ make_pair(5, 10.10) };
	pair pair3{ 5, 10.10 };
}
