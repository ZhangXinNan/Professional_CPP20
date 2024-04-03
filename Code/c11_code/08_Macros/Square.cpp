import <iostream>;

using namespace std;

#define SQUARE(x) ((x) * (x)) // No semicolon after the macro definition!
//#define SQUARE(x) (x * x)

int main()
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(2 + 3) << endl;
}
