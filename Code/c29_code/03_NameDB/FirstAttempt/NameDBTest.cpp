import name_db;
import <iostream>;

using namespace std;

int main()
{
	NameDB boys{ "boys_long.txt" };

	cout << boys.getNameRank("Daniel") << endl;
	cout << boys.getNameRank("Jacob") << endl;
	cout << boys.getNameRank("William") << endl;
}
