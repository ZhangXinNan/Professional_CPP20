import person;
import <iostream>;
import <sstream>;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };

	// Write person to standard output console.
	cout << person << endl;

	// Write person to a string stream.
	ostringstream output;
	output << person;
	// Verify the contents of the string stream.
	cout << output.str() << endl;

	// Read the person back from the string stream.
	istringstream input{ output.str() };
	Person person2;
	input >> person2;

	// Verify the read-back person.
	cout << person2 << endl;
}
