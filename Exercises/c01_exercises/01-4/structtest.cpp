import <iostream>;
import <format>;
import <vector>;
import employee;

using namespace std;

int main()
{
	vector<HR::Employee> employees;

	employees.push_back(HR::Employee{
		.firstInitial = 'J',
		.lastInitial = 'W',
		.employeeNumber = 42,
		.salary = 80'000,
		.title = HR::Title::SeniorEngineer
		}
	);

	employees.push_back(HR::Employee{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 133,
		.salary = 64'000,
		.title = HR::Title::Engineer
		}
	);

	employees.push_back(HR::Employee{
		.firstInitial = 'B',
		.lastInitial = 'P',
		.employeeNumber = 18,
		.salary = 100'000,
		.title = HR::Title::Manager
		}
	);

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
