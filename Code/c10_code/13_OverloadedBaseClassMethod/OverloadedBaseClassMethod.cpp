import <iostream>;

using namespace std;

class Base
{
public:
	virtual ~Base() = default;
	virtual void overload() { cout << "Base's overload()" << endl; }
	virtual void overload(int i) {
		cout << "Base's overload(int i)" << endl;
	}
};

class Derived : public Base
{
public:
	//using Base::overload;
	void overload() override {
		cout << "Derived's overload()" << endl;
	}
};

int main()
{
	{
		Derived myDerived;
		//myDerived.overload(2); // Error! No matching method for overload(int).
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		ref.overload(7);
	}
}
