import <iostream>;

using namespace std;

class Base
{
public:
	void go() { cout << "go() called on Base" << endl; }
};

class Derived : public Base
{
public:
	void go() { cout << "go() called on Derived" << endl; }
};

int main()
{
	{
		Derived myDerived;
		myDerived.go();
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		ref.go();
	}
}
