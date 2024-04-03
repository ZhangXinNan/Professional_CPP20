#include <cstddef>
import <iostream>;
import <string>;

using namespace std;

const size_t BufferSize{ 1024 };

int main()
{
	char buffer[BufferSize]{ 0 };
	cin.getline(buffer, BufferSize);

	cout << "***" << buffer << "***" << endl;

	string myString;
	getline(cin, myString);

	cout << "***" << myString << "***" << endl;
}
