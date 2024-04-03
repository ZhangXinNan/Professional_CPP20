import <iostream>;
import <memory>;

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

unique_ptr<Simple> create()
{
	auto ptr{ make_unique<Simple>() };
	// Do something with ptr...
	return ptr;
}

int main()
{
	unique_ptr<Simple> mySmartPtr1{ create() };
	auto mySmartPtr2{ create() };
}
