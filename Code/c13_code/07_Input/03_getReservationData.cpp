import <iostream>;
import <string>;

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize;
	cout << "Name and number of guests: ";
	cin >> guestName >> partySize;
	cout << "Thank you, " << guestName << "." << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

int main()
{
	getReservationData();
}
