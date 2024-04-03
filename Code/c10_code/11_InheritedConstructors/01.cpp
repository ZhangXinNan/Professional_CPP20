import <string_view>;

class Base
{
public:
	virtual ~Base() = default;
	Base() = default;
	Base(std::string_view str) {}
};

class Derived : public Base
{
public:
	using Base::Base;
	Derived(int i) {}
};

int main()
{
	Base base{ "Hello" };        // OK, calls string_view Base ctor.
	Derived derived1{ 1 };       // OK, calls integer Derived ctor.
	Derived derived2{ "Hello" }; // OK, calls inherited string_view Base ctor.
	Derived derived3;            // OK, calls inherited default Base ctor.
}
