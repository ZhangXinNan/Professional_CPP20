import <iostream>;
import <format>;
import <array>;
import employee;

using namespace std;

int main()
{
	// Create and populate 3 employees using C++20 designated initializers.
	HR::Employee employee1{
		.firstInitial = 'J',
		.lastInitial = 'W',
		.employeeNumber = 42,
		.salary = 80'000,
		.title = HR::Title::SeniorEngineer
	};

	HR::Employee employee2{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 133,
		.salary = 64'000,
		.title = HR::Title::Engineer
	};

	HR::Employee employee3{
		.firstInitial = 'B',
		.lastInitial = 'P',
		.employeeNumber = 18,
		.salary = 100'000,
		.title = HR::Title::Manager
	};

	array<HR::Employee, 3> employees{
		employee1, employee2, employee3
	};

	for (const auto& employee : employees) {
		// output the values of an employee
		cout << format("Employee: {}{}", employee.firstInitial,
			employee.lastInitial) << endl;
		cout << format("Number: {}", employee.employeeNumber) << endl;
		cout << format("Salary: ${}", employee.salary) << endl;

		switch (employee.title)
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
		cout << endl;
	}
}
