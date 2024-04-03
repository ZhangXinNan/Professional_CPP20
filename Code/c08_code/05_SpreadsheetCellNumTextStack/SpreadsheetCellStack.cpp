import spreadsheet_cell;
import <iostream>;
import <string>;

using namespace std;

int main()
{
	SpreadsheetCell myCell, anotherCell;
	myCell.setValue(6);
	anotherCell.setString("3.2");

	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	cout << "cell 1: " << myCell.getString() << endl;
	cout << "cell 2: " << anotherCell.getString() << endl;
}
