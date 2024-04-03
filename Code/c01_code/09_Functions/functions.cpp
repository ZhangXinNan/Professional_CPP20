import <iostream>;
import <format>;

using namespace std;

void myFunction(int i, char c);

void myFunction(int i, char c)
{
	cout << format("the value of i is {}", i) << endl;
	cout << format("the value of c is {}", c) << endl;
}

int addNumbers(int number1, int number2)
{
	cout << format("Entering function {}", __func__) << endl;
	return number1 + number2;
}

// With function return type deduction
//auto addNumbers(int number1, int number2)
//{
//	cout << format("Entering function {}", __func__) << endl;
//	return number1 + number2;
//}

double addNumbers(double a, double b)
{
	return a + b;
}

int main()
{
	int someInt{ 6 };
	char someChar{ 'c' };
	myFunction(8, 'a');
	myFunction(someInt, 'b');
	myFunction(5, someChar);

	int sum{ addNumbers(5, 3) };

	cout << addNumbers(1, 2) << endl; // Calls the integer version
	cout << addNumbers(1.11, 2.22);   // Calls the double version
}
