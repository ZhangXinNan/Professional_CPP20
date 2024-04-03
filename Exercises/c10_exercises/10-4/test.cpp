import hr;
import <iostream>;
import <string>;

using namespace std;

int main()
{
	HR::Employee employee{ 123, "Carlie", "Dudley" };
	cout << employee.toString() << endl;

	// Promote employee to manager.
	HR::Manager manager{ employee };
	cout << manager.toString() << endl;
}
