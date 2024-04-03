import <filesystem>;
import <iostream>;

using namespace std;
using namespace std::filesystem;

int main()
{
	path p1{ R"(D:\Foo\Bar)" };
	path p2{ "D:/Foo/Bar" };
	path p3{ "D:/Foo/Bar/MyFile.txt" };
	path p4{ R"(..\SomeFolder)" };
	path p5{ "/usr/lib/X11" };

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;
}
