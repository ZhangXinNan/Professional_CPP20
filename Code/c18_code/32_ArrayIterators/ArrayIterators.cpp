#include <cstddef>
import <vector>;
import <iostream>;

using namespace std;

int main()
{
	const size_t count{ 10 };
	int values[count];     // standard C-style array

	// Initialize each element of the array to the value of its index.
	for (int i{ 0 }; i < count; i++) {
		values[i] = i;
	}

	// Insert the contents of the array at the end of a vector.
	vector<int> vec;
	vec.insert(end(vec), values, values + count);
	// Use std::cbegin() and std::cend()
	//vec.insert(end(vec), cbegin(values), cend(values));

	// Print the contents of the vector.
	for (const auto& i : vec) {
		cout << i << " ";
	}
}
