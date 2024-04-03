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
		.salary = 80'000,
		.title = HR::Title::SeniorEngineer
	};

	// output the values of an employee
	cout << format("Employee: {}{}", anEmployee.firstInitial, 
		anEmployee.lastInitial) << endl;
	cout << format("Number: {}", anEmployee.employeeNumber) << endl;
	cout << format("Salary: ${}", anEmployee.salary) << endl;

	switch (anEmployee.title)
	{
		using enum HR::Title;

		case Engineer:
			cout << "Engineer" << endl;
			break;
		case SeniorEngineer:
			cout << "Senior Engineer" << endl;
			break;
		case Manager:
			cout << "Manager" << endl;
			break;
	}
}
