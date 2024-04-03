import <memory>;

using namespace std;

class MyClass {};

int main()
{
	// Create an allocator to use.
	allocator<MyClass> alloc;

	// Allocate uninitialized memory block.
	auto* memory{ alloc.allocate(1) };

	// Use placement new operator to construct a MyClass in place.
	new(memory) MyClass{};

	// Destroy MyClass instance.
	destroy_at(memory);

	// Deallocate memory block.
	alloc.deallocate(memory, 1);
	memory = nullptr;
}
