import <filesystem>;
import <iostream>;

using namespace std;
using namespace std::filesystem;

int main()
{
	path p{ "D:\\Foo" };
	p.append("Bar");
	p /= "Bar";
	cout << p << endl;
}
