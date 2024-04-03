import spreadsheet_cell;
import <iostream>;

using namespace std;

int main()
{
	SpreadsheetCell cell{ 6.6 };

	double d1{ cell + 3.3 };
	cout << d1 << endl;
}
