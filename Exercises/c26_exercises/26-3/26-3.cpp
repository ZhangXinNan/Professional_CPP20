import <iostream>;

using namespace std;

consteval unsigned long long fibonacci(unsigned int n)
{
	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }

	unsigned long long a{ 0 };
	unsigned long long b{ 1 };
	
	unsigned long long result{ 0 };
	for (unsigned int i{ 1 }; i < n; ++i) {
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main()
{
	cout << fibonacci(0) << endl;
	cout << fibonacci(1) << endl;
	cout << fibonacci(2) << endl;
	cout << fibonacci(3) << endl;
	cout << fibonacci(4) << endl;
	cout << fibonacci(5) << endl;
	cout << fibonacci(6) << endl;
	cout << fibonacci(7) << endl;
	cout << fibonacci(8) << endl;
	cout << fibonacci(9) << endl;
	cout << fibonacci(10) << endl;
	cout << fibonacci(11) << endl;
}