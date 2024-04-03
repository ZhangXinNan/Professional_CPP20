import <iostream>;

using namespace std;

template<typename... Values>
double allTrue(const Values&... values) { return (... && values); }

template<typename... Values>
double anyTrue(const Values&... values) { return (... || values); }

int main()
{
	cout << allTrue(1, 1, 0) << allTrue(1, 1) << allTrue() << endl; // 011
	cout << anyTrue(1, 1, 0) << anyTrue(0, 0) << anyTrue() << endl; // 100
}
