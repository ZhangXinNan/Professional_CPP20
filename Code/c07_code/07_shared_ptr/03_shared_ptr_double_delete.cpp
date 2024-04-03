import <memory>;
import <iostream>;

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

void doubleDelete()
{
	Simple* mySimple{ new Simple{} };
	shared_ptr<Simple> smartPtr1(mySimple);
	shared_ptr<Simple> smartPtr2(mySimple);
}

void noDoubleDelete()
{
	auto smartPtr1{ make_shared<Simple>() };
	auto smartPtr2{ smartPtr1 };
}

int main()
{
	//doubleDelete();  // BUG, might cause a crash!
	noDoubleDelete();
}
