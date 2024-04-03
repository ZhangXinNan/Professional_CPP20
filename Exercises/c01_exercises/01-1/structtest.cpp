import <iostream>;
import <format>;
import employee;

using namespace std;

int main()
{
	// Create and populate an employee using C++20 designated initializers.
	HR::Employee anEmployee {
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 42,
		.salary = 80'000
	};

	// output the values of an employee
	cout << format("Employee: {}{}", anEmployee.firstInitial, 
		anEmployee.lastInitial) << endl;
	cout << format("Number: {}", anEmployee.employeeNumber) << endl;
	cout << format("Salary: ${}", anEmployee.salary) << endl;
}
