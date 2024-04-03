#include <cstdint>  // For fixed-size integer types.
import <iostream>;

using namespace std;

// Changes encoding from little to big endian or vice versa.
// Swaps bytes of a 16-bit unsigned integer.
uint16_t swapEndianness(uint16_t value)
{
	return (value << 8) | (value >> 8);
}

// Changes encoding from little to big endian or vice versa.
// Swaps bytes of a 32-bit unsigned integer.
uint32_t swapEndianness(uint32_t value)
{
	return ((value << 24) & 0xff000000) | // Move byte 0 to byte 3.
		((value << 8) & 0xff0000) |       // Move byte 1 to byte 2.
		((value >> 8) & 0xff00) |         // Move byte 2 to byte 1.
		((value >> 24) & 0xff);           // Move byte 3 to byte 0.
}

int main()
{
	{
		uint16_t u{ 1234 };
		uint16_t swapped{ swapEndianness(u) };
		uint16_t swappedBack{ swapEndianness(swapped) };
		cout << u << " " << swapped << " " << swappedBack << endl;
	}

	{
		uint32_t i{ 123456789 };
		uint32_t swapped{ swapEndianness(i) };
		uint32_t swappedBack{ swapEndianness(swapped) };
		cout << i << " " << swapped << " " << swappedBack << endl;
	}
}