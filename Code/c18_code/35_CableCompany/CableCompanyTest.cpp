import cable_company;
import <iostream>;

using namespace std;

int main()
{
	CableCompany myCC;
	myCC.addPackage("basic",   "1111000000");
	myCC.addPackage("premium", "1111111111");
	myCC.addPackage("sports",  "0000100111");

	myCC.newCustomer("Marc G.", "basic");
	myCC.addPackageToCustomer("Marc G.", "sports");
	cout << myCC.getCustomerChannels("Marc G.") << endl;
}
