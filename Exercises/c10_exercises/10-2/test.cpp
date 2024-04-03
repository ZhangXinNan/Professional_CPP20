import hr;
import <iostream>;
import <string>;

using namespace std;

int main()
{
	HR::Person person{ "Otis", "Lowe" };
	HR::Employee employee{ 123, "Otis", "Lowe" };

	cout << person.toString() << endl;
	cout << employee.toString() << endl;
}
