import <string>;
import <iostream>;

using namespace std;

int main()
{
	string myString;

	myString.insert(cend(myString), 'h');
	myString.insert(cend(myString), 'e');
	myString.push_back('l');
	myString.push_back('l');
	myString.push_back('o');

	for (const auto& letter : myString) {
		cout << letter;
	}
	cout << endl;

	for (auto it{ cbegin(myString) }; it != cend(myString); ++it) {
		cout << *it;
	}
	cout << endl;
}
