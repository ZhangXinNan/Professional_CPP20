import <iostream>;
import <string>;

using namespace std;

void fillWithM(string& text)
{
	for (auto& character : text) {
		character = 'm';
	}
}


int main()
{
	string hello{ "Hello world!" };
	cout << "Before: " << hello << endl;

	fillWithM(hello);

	cout << "After:  " << hello << endl;
}
