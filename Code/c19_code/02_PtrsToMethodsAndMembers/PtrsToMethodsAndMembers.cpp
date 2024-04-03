import employee;
import <iostream>;

using namespace std;
using namespace Records;

int main()
{
	{
		// Old style:
		//int (Employee::*methodPtr) () const { &Employee::getSalary };

		// Using a type alias:
		//using PtrToGet = int (Employee::*) () const;
		//PtrToGet methodPtr{ &Employee::getSalary };

		// Using auto:
		auto methodPtr{ &Employee::getSalary };

		Employee employee{ "John", "Doe" };
		cout << (employee.*methodPtr)() << endl;
	}

	{
		int (Employee::*methodPtr) () const { &Employee::getSalary };
		Employee* employee{ new Employee{ "John", "Doe"} };
		cout << (employee->*methodPtr)() << endl;
		delete employee;
	}
}
