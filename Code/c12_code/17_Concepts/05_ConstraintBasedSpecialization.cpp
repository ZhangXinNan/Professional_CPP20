#include <cstddef>
import <iostream>;
import <array>;
import <concepts>;
import <limits>;

using namespace std;

static const size_t NOT_FOUND{ static_cast<size_t>(-1) };

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	cout << "Generic version" << endl;
	for (size_t i{ 0 }; i < size; i++) {
		if (arr[i] == value) {
			return i; // Found it; return the index.
		}
	}
	return NOT_FOUND; // Failed to find it; return NOT_FOUND.
}

template <typename T, size_t N>
size_t Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

template <std::floating_point T>
bool AreEqual(T x, T y, int precision = 2)
{
	// Scale the machine epsilon to the magnitude of the given values and multiply
	// by the required precision.
	return fabs(x - y) <= numeric_limits<T>::epsilon() * fabs(x + y) * precision
		|| fabs(x - y) < numeric_limits<T>::min(); // The result is subnormal.
}

template <std::floating_point T>
size_t Find(const T& value, const T* arr, size_t size)
{
	cout << "floating_point version" << endl;
	for (size_t i{ 0 }; i < size; i++) {
		if (AreEqual(arr[i], value)) {
			return i; // Found it; return the index.
		}
	}
	return NOT_FOUND; // Failed to find it; return NOT_FOUND.
}

int main()
{
	int myInt{ 3 }, intArray[]{ 1, 2, 3, 4 };
	const size_t sizeIntArray{ size(intArray) };

	size_t res;
	res = Find(myInt, intArray, sizeIntArray);        // calls Find<int> by deduction.
	res = Find<int>(myInt, intArray, sizeIntArray);   // calls Find<int> explicitly.
	res = Find(myInt, intArray);
	if (res != NOT_FOUND) { cout << res << endl; }
	else { cout << "Not found" << endl; }

	double myDouble{ 5.7 }, doubleArray[]{ 1.2, 3.4, 5.7, 7.5 };
	const size_t sizeDoubleArray{ size(doubleArray) };

	res = Find(myDouble, doubleArray, sizeDoubleArray);         // calls Find<double> by deduction.
	res = Find<double>(myDouble, doubleArray, sizeDoubleArray); // calls Find<double> explicitly.
	if (res != NOT_FOUND) { cout << res << endl; }
	else { cout << "Not found" << endl; }

	//res = Find(myInt, doubleArray, sizeDoubleArray);        // DOES NOT COMPILE! Arguments are different types.
	res = Find<double>(myInt, doubleArray, sizeDoubleArray);  // calls Find<double> explicitly, even with myInt.
}
