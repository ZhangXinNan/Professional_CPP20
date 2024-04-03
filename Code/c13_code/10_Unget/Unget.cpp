#include <cctype>
import <iostream>;
import <string>;
import <format>;

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize{ 0 };
	// Read characters until we find a digit
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail())
				cout << "unget() failed" << endl;
			break;
		}
		guestName += ch;
	}
	// Read partysize, if the stream is not in error state
	if (cin)
		cin >> partySize;
	if (!cin) {
		cerr << "Error getting party size." << endl;
		return;
	}

	cout << format("Thank you '{}', party of {}",
		guestName, partySize) << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

int main()
{
	getReservationData();
}
