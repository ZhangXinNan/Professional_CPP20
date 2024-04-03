import <iostream>;

using namespace std;

class Base
{
public:
	void someMethod() {}

protected:
	int m_protectedInt{ 0 };

private:
	int m_privateInt{ 0 };
};

class Derived : public Base
{
public:
	void someOtherMethod()
	{
		cout << "I can access base class data member m_protectedInt." << endl;
		cout << "Its value is " << m_protectedInt << endl;
		//cout << "The value of m_privateInt is " << m_privateInt << endl; // Error!
	}
};

int main()
{
	Derived myDerived;
	myDerived.someMethod();
	myDerived.someOtherMethod();

	Base myBase;
	//myBase.someOtherMethod();  // Error! Base doesn't have a someOtherMethod().

	Base* base{ new Derived{} }; // Create Derived, store in Base pointer.

	//base->someOtherMethod();  // Error! Base doesn't have a someOtherMethod().
}
