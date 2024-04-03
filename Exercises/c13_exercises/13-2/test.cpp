import person;
import <iostream>;
import <sstream>;
import <fstream>;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };

	// Write person to standard output console.
	person.output(cout);

	// Write person to a string stream.
	ostringstream oss;
	person.output(oss);
	// Verify the contents of the string stream.
	cout << oss.str() << endl;

	// Write person to a file.
	ofstream outFile{ "person.txt" };
	person.output(outFile);
}
