import <iostream>;
import <memory>;

using namespace std;

int main()
{
	{
		double pi{ 3.1415 };
		auto myLambda{ [myCapture = "Pi: ", pi] { cout << myCapture << pi; } };
		myLambda();
	}

	cout << endl;

	{
		auto myPtr{ make_unique<double>(3.1415) };
		auto myLambda{ [p = move(myPtr)] { cout << *p; } };
		myLambda();
	}

	cout << endl;

	{
		auto myPtr{ make_unique<double>(3.1415) };
		auto myLambda{ [myPtr = move(myPtr)] { cout << *myPtr; } };
		myLambda();
	}

	cout << endl;
}
