import <iostream>;

using namespace std;

int* getData(int value)
{
	return new int{ value * 2 };
}

int main()
{
	int* data{ getData(21) };
	cout << *data << endl;
	//// Memory leak! Memory for data is not deleted.
	//// Following line needs to be added:
	delete data; data = nullptr;

	data = getData(42);
	cout << *data << endl;
	//// Memory leak! Memory for data is not deleted.
	//// Following line needs to be added:
	delete data; data = nullptr;
}