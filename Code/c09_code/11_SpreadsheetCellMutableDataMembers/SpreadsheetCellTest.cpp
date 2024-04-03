import spreadsheet_cell;
import <iostream>;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 5 };
	cout << myCell.getValue() << endl;
}
