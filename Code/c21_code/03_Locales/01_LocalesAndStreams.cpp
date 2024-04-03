import <locale>;
import <iostream>;

using namespace std;

int main()
{
	wcout.imbue(locale{ "" });
	wcout << 32767 << endl;

	wcout.imbue(locale{ "C" });
	wcout << 32767 << endl;

	wcout.imbue(locale{ "en-US" }); // "en_US" for POSIX
	wcout << 32767 << endl;
}