import <tuple>;
import <iostream>;

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << apply(add, tuple{ 39, 3 }) << endl;
}