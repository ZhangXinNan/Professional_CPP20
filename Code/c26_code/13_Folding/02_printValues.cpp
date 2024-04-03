import <iostream>;

using namespace std;

template<typename... Values>
void printValues(const Values&... values)
{
	((cout << values << endl), ...);
}

int main()
{
	printValues(1, "test", 2.34);
}