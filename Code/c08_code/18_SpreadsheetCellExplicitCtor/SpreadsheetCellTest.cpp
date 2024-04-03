import spreadsheet_cell;
import <iostream>;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 4 };
	myCell = 5;
	//myCell = "6"sv; // A string_view literal (see Chapter 2).

	cout << "Cell 1: " << myCell.getValue() << endl;
}
