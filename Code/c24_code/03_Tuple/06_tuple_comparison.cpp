import <string>;
import <iostream>;
import <tuple>;

using namespace std;

int main()
{
	tuple t1{ 123, "def"s };  // Using CTAD.
	tuple t2{ 123, "abc"s };
	// Or:
	//tuple<int, string> t1{ 123, "def" };
	//tuple<int, string> t2{ 123, "abc" };

	if (t1 < t2) {
		cout << "t1 < t2" << endl;
	} else {
		cout << "t1 >= t2" << endl;
	}
}
