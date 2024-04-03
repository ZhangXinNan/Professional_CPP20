#include <cstring>
import <iostream>;

using namespace std;

int main()
{
	const char* test{ "hello there\n" };
	cout.write(test, strlen(test));
}
