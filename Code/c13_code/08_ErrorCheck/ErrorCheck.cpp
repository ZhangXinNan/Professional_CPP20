import <iostream>;
import <string>;

using namespace std;

int main()
{
	cout << "Enter numbers on separate lines to add.\n"
		<< "Use Control+D followed by Enter to finish (Control+Z in Windows).\n";
	int sum{ 0 };

	if (!cin.good()) {
		cerr << "Standard input is in a bad state!" << endl;
		return 1;
	}

	while (!cin.bad()) {
		int number;
		cin >> number;
		if (cin.good()) {
			sum += number;
		} else if (cin.eof()) {
			break; // Reached end of file
		} else if (cin.fail()) {
			// Failure!
			cin.clear(); // Clear the failure state.
			string badToken;
			cin >> badToken; // Consume the bad input.
			cerr << "WARNING: Bad input encountered: " << badToken << endl;
		}
	}

	cout << "The sum is " << sum << endl;
}
