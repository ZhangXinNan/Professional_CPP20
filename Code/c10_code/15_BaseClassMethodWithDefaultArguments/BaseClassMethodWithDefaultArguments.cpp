import <iostream>;

using namespace std;

class Base
{
public:
	virtual ~Base() = default;
	virtual void go(int i = 2) {
		cout << "Base's go with i=" << i << endl;
	}
};

class Derived : public Base
{
public:
	void go(int i = 7) override {
		cout << "Derived's go with i=" << i << endl;
	}
};

int main()
{
	Base myBase;
	Derived myDerived;
	Base& myBaseReferenceToDerived{ myDerived };
	myBase.go();
	myDerived.go();
	myBaseReferenceToDerived.go();
}
