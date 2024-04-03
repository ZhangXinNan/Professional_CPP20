import <iostream>;

using namespace std;

consteval unsigned long long factorial(unsigned char f)
{
	if (f == 0) {
		return 1;
	} else {
		return f * factorial(f - 1);
	}
}

int main()
{
	cout << factorial(6) << endl;
}
