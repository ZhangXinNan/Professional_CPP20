import <iostream>;
import <memory>;

using namespace std;

class Demo
{
public:
	int get() { return 5; }
};

int get() { return 10; }

namespace NS
{
	int get() { return 20; }
}

int main()
{
	Demo d;
	cout << d.get() << endl;      // prints 5
	cout << NS::get() << endl;    // prints 20
	cout << ::get() << endl;      // prints 10
	cout << get() << endl;        // prints 10
}
