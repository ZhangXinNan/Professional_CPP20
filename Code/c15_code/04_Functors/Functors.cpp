import <string_view>;

using namespace std;

class FunctionObject
{
public:
	int operator() (int param);  // Function call operator
	void operator() (string_view /*str*/) {}
	int doSquare(int param);     // Normal method
};

// Implementation of overloaded function call operator
int FunctionObject::operator() (int param)
{
	return doSquare(param);
}

// Implementation of normal method
int FunctionObject::doSquare(int param)
{
	return param * param;
}

int main()
{
	int x{ 3 }, xSquared, xSquaredAgain;
	FunctionObject square;

	xSquared = square(x);               // Call the function call operator.
	xSquaredAgain = square.doSquare(x); // Call the normal method.
}

