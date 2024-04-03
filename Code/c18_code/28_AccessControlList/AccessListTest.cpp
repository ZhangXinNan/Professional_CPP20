import access_list;
import <iostream>;

using namespace std;

int main()
{
	AccessList fileX{ "mgregoire", "baduser" };
	fileX.addUser("pvw");
	fileX.removeUser("baduser");

	if (fileX.isAllowed("mgregoire")) {
		cout << "mgregoire has permissions" << endl;
	}

	if (fileX.isAllowed("baduser")) {
		cout << "baduser has permissions" << endl;
	}

	auto users{ fileX.getAllUsers() };
	for (const auto& user : users) {
		cout << user << "  ";
	}
	cout << endl;
}
