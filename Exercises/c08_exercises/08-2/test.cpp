import person;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };
	cout << format("{} {}", person.getFirstName(), person.getLastName()) << endl;

	Person persons[3];
}
