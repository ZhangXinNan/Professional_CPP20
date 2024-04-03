import person;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };
	cout << format("The initials of {} {} are {}.",
		person.getFirstName(), person.getLastName(), person.getInitials()) << endl;

	Person person2{ "Marc", "Gregoire", "Mg" };
	cout << format("The initials of {} {} are {}.",
		person2.getFirstName(), person2.getLastName(), person2.getInitials()) << endl;

	Person persons[3];

	// Test copy constructor.
	Person copy{ person };

	// Test assignment operator.
	Person otherPerson{ "Jane", "Doe" };
	copy = otherPerson;
}
