export module derived_simple;

export import simple;

// A class derived from the Simple class.
export class DerivedSimple : public Simple
{
public:
	DerivedSimple() : Simple{} // Constructor
	{ /* Implementation of constructor */ }

	void publicMethod() override // Overridden method
	{
		// Implementation of overridden method
		Simple::publicMethod(); // You can access base class implementations.
	}

	virtual void anotherMethod() // New method
	{ /* Implementation of new method */ }
};
