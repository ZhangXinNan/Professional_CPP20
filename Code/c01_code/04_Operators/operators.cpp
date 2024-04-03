import <iostream>;

using namespace std;

int main()
{
	int someInteger{ 256 };
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;

	someInteger++;
	someInteger *= 2;
	someShort = static_cast<short>(someInteger);
	someLong = someShort * 10000;
	someFloat = someLong + 0.785f;
	someDouble = static_cast<double>(someFloat) / 100000;

	cout << someDouble << endl;
}
