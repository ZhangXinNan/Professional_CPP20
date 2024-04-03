#include <cstdlib>
import <iostream>;

using namespace std;

void memoryLeak()
{
	int* p{ new int[1000] };
	return; // BUG! Not freeing p
}

void mismatchedFree()
{
	int* p1{ (int*)malloc(sizeof(int)) };
	int* p2{ new int };
	int* p3{ new int[1000] };
	delete p1;    // BUG! Should use free()
	delete [] p2; // BUG! Should use delete
	free(p3);     // BUG! Should use delete []
}

void doubleFree()
{
	int* p1{ new int[1000] };
	delete [] p1;
	int* p2{ new int[1000] };
	delete [] p1; // BUG! freeing p1 twice
} // BUG! Leaking memory of p2

void freeUnallocated()
{
	int* p{ reinterpret_cast<int*>(10000) };
	delete p; // BUG! p is not a valid pointer
}

void freeStack()
{
	int x;
	int* p{ &x };
	delete p; // BUG! Freeing stack memory
}

void accessInvalid()
{
	int* p{ reinterpret_cast<int*>(10000) };
	*p = 5;    // BUG! p is not a valid pointer
}

void accessFreed()
{
	int* p1{ new int };
	delete p1;
	int* p2{ new int };
	*p1 = 5; // BUG! The memory pointed to by p1 has been freed
}

void accessElsewhere()
{
	int x, y[10], z;
	x = 0;
	z = 0;
	for (int i{ 0 }; i <= 10; i++) {
		y[i] = 5; // BUG for i==10! element 10 is past the end of the array
	}
}

void readUninitialized()
{
	int* p;
	cout << *p << endl; // BUG! p is uninitialized
}

int main()
{
	cout << "Memory leak" << endl;
	memoryLeak();
	cout << "Mismatched Free" << endl;
	mismatchedFree();
	cout << "Double Free" << endl;
	doubleFree();
	cout << "Free Unallocated" << endl;
	freeUnallocated();
	cout << "Free Stack" << endl;
	freeStack();
	cout << "Access Invalid" << endl;
	accessInvalid();
	cout << "Access Freed" << endl;
	accessFreed();
	cout << "Access Elsewhere" << endl;
	accessElsewhere();
	cout << "Read Uninitialized" << endl;
	readUninitialized();
}
