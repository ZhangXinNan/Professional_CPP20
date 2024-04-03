#include <cstddef>
#include <cstring>
import <iostream>;
import <array>;

using namespace std;

static const size_t NOT_FOUND{ static_cast<size_t>(-1) };

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	cout << "original" << endl;
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

size_t Find(const char* value, const char** arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i{ 0 }; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // Found it; return the index.
		}
	}
	return NOT_FOUND; // Failed to find it; return NOT_FOUND.
}

int main()
{
	const char* word{ "two" };
	const char* words[]{ "one", "two", "three", "four" };
	const size_t sizeWords{ size(words) };
	size_t res{ Find(word, words, sizeWords) }; // Calls non-template function.
	if (res != NOT_FOUND) { cout << res << endl; }
	else { cout << "Not found" << endl; }

	res = Find<const char*>(word, words, sizeWords); // Calls template with T=const char*.
}
