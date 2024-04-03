import <array>;

int main()
{
	{
		int myArray[3];
		myArray[0] = 0;
		myArray[1] = 0;
		myArray[2] = 0;
	}

	{
		int myArray[3] = { 0 };
	}

	{
		int myArray[3] = {};
	}

	{
		int myArray[3]{};
	}

	{
		int myArray[]{ 1, 2, 3, 4 }; // The compiler creates an array of 4 elements.
	}

	{
		int myArray[3]{ 2 };
		size_t arraySize{ std::size(myArray) };
	}
}
