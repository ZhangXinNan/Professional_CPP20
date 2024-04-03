#include <cstddef>
import <new>;

class MyClass
{
public:
	void* operator new(size_t size) = delete;
	void* operator new[](size_t size) = delete;
};

int main()
{
	// It is possible to create instances of MyClass on the stack.
	MyClass classOnStack;

	// It is not possible to create them on the free store.
	// The following two lines do not compile.
	//MyClass* p1{ new MyClass };
	//MyClass* p2{ new MyClass[2] };
}
