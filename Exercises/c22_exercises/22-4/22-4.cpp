import <iostream>;
import <chrono>;

using namespace std;
using namespace std::chrono;

int main()
{
	cout << weekday{ 2020y / June / 22d } << endl;
}
