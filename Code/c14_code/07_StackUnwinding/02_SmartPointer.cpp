import <fstream>;
import <iostream>;
import <stdexcept>;
import <memory>;

using namespace std;

void funcOne();
void funcTwo();

int main()
{
	try {
		funcOne();
	} catch (const exception& /* e */) {
		cerr << "Exception caught!" << endl;
		return 1;
	}
}

void funcOne()
{
	string str1;
	auto str2{ make_unique<string>("hello") };
	funcTwo();
}

void funcTwo()
{
	ifstream fileStream;
	fileStream.open("filename");
	throw exception {};
	fileStream.close();
}
