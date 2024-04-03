import <iostream>;
import <format>;

using namespace std;

int main()
{
	char c;
	cin >> c;
	cout << format("Retrieved {} before putback('e').", c) << endl;

	cin.putback('e');  // 'e' will be the next character read off the stream.
	cin >> c;
	cout << format("Retrieved {} after putback('e').", c) << endl;
}
