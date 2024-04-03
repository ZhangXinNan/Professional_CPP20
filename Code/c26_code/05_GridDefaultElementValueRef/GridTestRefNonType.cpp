import grid;
import spreadsheet_cell;
import <iostream>;
import <string>;

using namespace std;

namespace {
	int defaultInt{ 11 };
	SpreadsheetCell defaultCell{ 1.2 };
}

int main()
{
	Grid<int, defaultInt> myIntGrid;
	Grid<SpreadsheetCell, defaultCell> mySpreadsheet;

	Grid<int, defaultInt> myIntGrid2{ myIntGrid };
	myIntGrid2.at(1, 2) = 3;

	cout << myIntGrid.at(1, 2).value_or(-1) << endl;
	cout << myIntGrid2.at(1, 2).value_or(-1) << endl;

	cout << mySpreadsheet.at(1, 2).value().getString() << endl;
}
