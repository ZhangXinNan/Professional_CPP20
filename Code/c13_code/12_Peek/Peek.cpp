import <iostream>;
import <string>;
import <format>;

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize{ 0 };
	// Read characters until we find a digit
	cin >> noskipws;
	while (true) {
		// 'peek' at next character
		char ch{ static_cast<char>(cin.peek()) };
		if (!cin)
			break;
		if (isdigit(ch)) {
			// next character will be a digit, so stop the loop
			break;
		}
		// next character will be a non-digit, so read it
		cin >> ch;
		if (!cin)
			break;
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
