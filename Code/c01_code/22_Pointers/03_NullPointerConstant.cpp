import <iostream>;

using namespace std;

void func(int i) { cout << "func(int)" << endl; }

int main()
{
	func(NULL);
	//func(nullptr); // Compilation error.
}
