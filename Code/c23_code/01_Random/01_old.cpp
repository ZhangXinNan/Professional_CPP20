#include <ctime>
import <iostream>;

using namespace std;

int getRandom(int min, int max)
{
	return static_cast<int>(rand() % (max + 1UL - min)) + min;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	cout << rand() << endl;

	cout << getRandom(1, 6) << endl;
}
