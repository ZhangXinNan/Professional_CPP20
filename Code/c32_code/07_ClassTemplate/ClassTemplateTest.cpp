import simple_wrapper;
import <iostream>;
import <string>;

using namespace std;

int main()
{
	// Try wrapping an integer
	int i{ 7 };
	SimpleWrapper intWrapper{ i };  // Using CTAD.
	// Or without class template argument deduction (CTAD).
	//SimpleWrapper<int> intWrapper{ i };
	i = 2;
	cout << "wrapped value is " << intWrapper.get() << endl;

	// Try wrapping a string
	string str{ "test" };
	SimpleWrapper stringWrapper{ str };
	str += "!";
	cout << "wrapped value is " << stringWrapper.get() << endl;
}
