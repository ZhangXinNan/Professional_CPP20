using LambdaType = decltype([](int a, int b) { return a + b; }); // Unevaluated.

LambdaType getLambda()
{
	return LambdaType{}; // Default construction.
}

int main()
{
	auto lambda{ [](int a, int b) { return a + b; } }; // A stateless lambda.
	decltype(lambda) lambda2;	// Default construction.
	auto copy{ lambda };		// Copy construction.
	copy = lambda2;				// Copy assignment.
}