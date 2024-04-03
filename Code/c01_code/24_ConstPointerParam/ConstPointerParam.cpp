import <string>;

void mysteryFunction(const std::string* someString)
{
	*someString = "Test";  // Will not compile.
}

int main()
{
	std::string myString{ "The string" };
	mysteryFunction(&myString);
}
