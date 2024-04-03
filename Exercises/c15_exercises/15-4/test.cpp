import person;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	auto peter{ "Peter Van Weert"_p };

	cout << format("First name: {}", peter.getFirstName()) << endl;
	cout << format("Last name: {}", peter.getLastName()) << endl;
	cout << format("Initials: {}", peter.getInitials()) << endl;
}
