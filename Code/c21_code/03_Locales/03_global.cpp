import <iostream>;
import <sstream>;
import <locale>;

using namespace std;

void print()
{
	stringstream stream;
	stream << 32767;
	cout << stream.str() << endl;
}

int main()
{
	print();
	locale::global(locale{ "en-US" }); // "en_US" for POSIX
	print();
}