#include <cstddef>
import array;
import <iostream>;

using namespace std;

void printArray(const Array<int>& arr)
{
	for (size_t i{ 0 }; i < arr.getSize(); i++) {
		cout << arr[i] << " "; // Calls the const operator[] because arr is a const object.
	}
	cout << endl;
}

int main()
{
	{
		Array<int> myArray;
		for (size_t i{ 0 }; i < 10; i++) {
			myArray.setElementAt(i, 100);
		}
		for (size_t i{ 0 }; i < 10; i++) {
			cout << myArray.getElementAt(i) << " ";
		}
		cout << endl;
	}


	{
		Array<int> myArray;
		for (size_t i{ 0 }; i < 10; i++) {
			myArray[i] = 100;	// Calls the non-const operator[] because myArray is a non-const object.
		}
		for (size_t i{ 0 }; i < 10; i++) {
			cout << myArray[i] << " ";
		}

		cout << endl;

		printArray(myArray);
	}

	{
		Array<Array<int>> a;
		a[2][4] = 24;
		cout << a[2][4] << endl;
	}
}
