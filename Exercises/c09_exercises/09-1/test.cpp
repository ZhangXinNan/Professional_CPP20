import person;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	Person person { "John", "Doe" };
	cout << format("{} {}", person.getFirstName(), person.getLastName()) << endl;

	Person persons[3];

	// Test copy constructor.
	Person copy{ person };

	// Test assignment operator.
	Person otherPerson { "Jane", "Doe" };
	copy = otherPerson;

	// Test move construction.
	Person movedToPerson{ std::move(copy) };

	// Test move assignment.
	movedToPerson = std::move(person);
}
