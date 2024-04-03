constexpr int getArraySize()
{
	return 32;
}

int main()
{
	int myArray[getArraySize()];	// OK
	myArray[0] = 1;
}
