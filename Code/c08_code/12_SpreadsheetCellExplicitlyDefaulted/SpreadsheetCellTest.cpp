import spreadsheet_cell;
import <iostream>;
import <memory>;

using namespace std;

int main()
{
	SpreadsheetCell myCell;
	myCell.setValue(6);
	cout << "cell 1: " << myCell.getValue() << endl;

	auto smartCellp{ make_unique<SpreadsheetCell>() };
	// Or with a raw pointer (not recommended)
	SpreadsheetCell* myCellp{ new SpreadsheetCell{ } };
	// Or
	// SpreadsheetCell* myCellp{ new SpreadsheetCell };
	// ... use myCellp
	delete myCellp;    myCellp = nullptr;
}
