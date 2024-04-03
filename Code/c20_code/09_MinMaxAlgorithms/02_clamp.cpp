import <iostream>;
import <algorithm>;

using namespace std;

int main()
{
	cout << clamp(-3, 1, 10) << endl;
	cout << clamp(3, 1, 10) << endl;
	cout << clamp(22, 1, 10) << endl;
}
