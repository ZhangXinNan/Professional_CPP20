import spreadsheet_cell;
import <iostream>;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ "6.2" };
	cout << "cell 1: " << myCell.getValue() << endl;
}
