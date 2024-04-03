import <iostream>;
import <bit>;
import <format>;

using namespace std;

int main()
{
	cout << popcount(0b10101010u) << endl;  // 4

	uint8_t value{ 0b11101011u };
	cout << countl_one(value) << endl;  // 3
	cout << countr_one(value) << endl;  // 2

	value = 0b10001000u;
	cout << format("{:08b}", rotl(value, 2)) << endl; // 00100010

	value = 0b00001011u;
	cout << format("bit_ceil({0:08b} = {0}) = {1:08b} = {1}",
		value, bit_ceil(value)) << endl; // bit_ceil(00001011 = 11) = 00010000 = 16
	cout << format("bit_floor({0:08b} = {0}) = {1:08b} = {1}",
		value, bit_floor(value)) << endl; // bit_floor(00001011 = 11) = 00001000 = 8
}
