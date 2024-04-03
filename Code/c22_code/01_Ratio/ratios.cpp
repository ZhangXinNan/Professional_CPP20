import <iostream>;
import <ratio>;
import <format>;

using namespace std;

int main()
{
	// Define a compile-time rational number.
	using r1 = ratio<1, 60>;

	// Get numerator and denominator.
	intmax_t num{ r1::num };
	intmax_t den{ r1::den };
	cout << format("1) r1 = {}/{}", num, den) << endl;

	// Add two rational numbers.
	using r2 = ratio<1, 30>;
	cout << format("2) r2 = {}/{}", r2::num, r2::den) << endl;
	using result = ratio_add<r1, r2>::type;
	cout << format("3) sum = {}/{}", result::num, result::den) << endl;

	// Compare two rational numbers.
	using res = ratio_less<r2, r1>;
	cout << format("4) r2 < r1: {}", res::value) << endl;
}
