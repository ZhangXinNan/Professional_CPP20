import spreadsheet_cell;
import <iostream>;

using namespace std;

int main()
{
	SpreadsheetCell myCell { 5 };
	cout << myCell.getValue() << endl; // OK
	myCell.setString("6");             // OK

	const SpreadsheetCell& myCellConstRef{ myCell };
	cout << myCellConstRef.getValue() << endl; // OK
	//myCellConstRef.setString("6"); // Compilation Error!
}
