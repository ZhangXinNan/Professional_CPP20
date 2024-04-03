import person;
import person_database;
import <iostream>;

using namespace std;

int main()
{
	// Fill a database.
	Database db;
	db.add(Person{ "John", "Doe" });
	db.add(Person{ "Marc", "Gregoire", "Mg" });
	db.add(Person{ "Peter", "Van Weert", "PVW" });

	// Output all persons in the database to standard output.
	cout << "Initial database contents:" << endl;
	db.outputAll(cout);

	// Save the database to files.
	db.save("F:\\persons");

	// Clear the database.
	db.clear();
	cout << "\nDatabase contents after clearing:" << endl;
	db.outputAll(cout);
	
	// Load database from files.
	cout << "\nLoading database from files..." << endl;
	db.load("F:\\persons");
	cout << "\nDatabase contents after loading from files:" << endl;
	db.outputAll(cout);
}
