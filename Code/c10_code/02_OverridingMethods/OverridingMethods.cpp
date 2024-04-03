import <iostream>;

using namespace std;

class Base
{
public:
	virtual void someMethod()
	{
		cout << "This is Base's version of someMethod()." << endl;
	}

protected:
	int m_protectedInt{ 0 };

private:
	int m_privateInt{ 0 };
};

class Derived : public Base
{
public:
	void someMethod() override // Overrides Base's someMethod()
	{
		cout << "This is Derived's version of someMethod()." << endl;
	}

	virtual void someOtherMethod()
	{
		cout << "I can access base class data member m_protectedInt." << endl;
		cout << "Its value is " << m_protectedInt << endl;
		//cout << "The value of m_privateInt is " << m_privateInt << endl; // Error!
	}
};


int main()
{
	{
		Base myBase;
		myBase.someMethod();  // Calls Base's version of someMethod().
	}

	{
		Derived myDerived;
		myDerived.someMethod();   // Calls Derived's version of someMethod()
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		ref.someMethod();   // Calls Derived's version of someMethod()
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		myDerived.someOtherMethod();  // This is fine.
		// ref.someOtherMethod();     // Error
	}

	{
		Derived myDerived;
		Base assignedObject{ myDerived };  // Assigns a Derived to a Base.
		assignedObject.someMethod();       // Calls Base's version of someMethod()
	}
}
