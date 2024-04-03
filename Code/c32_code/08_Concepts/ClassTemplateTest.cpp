import simple_wrapper;
import <iostream>;
import <string>;

using namespace std;

int main()
{
	// Try wrapping an integer
	int i{ 7 };
	SimpleWrapper intWrapper{ i };
	i = 2;
	cout << "wrapped value is " << intWrapper.get() << endl;

	// The following now causes a compilation error.
	//string str{ "test" };
	//SimpleWrapper stringWrapper{ str };
	//str += "!";
	//cout << "wrapped value is " << stringWrapper.get() << endl;
}
