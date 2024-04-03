import spreadsheet_cell;
import <iostream>;
import <string>;
import <memory>;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 5 }, anotherCell{ 4 };
	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	auto smartCellp{ make_unique<SpreadsheetCell>(4) };
	// ... do something with the cell, no need to delete the smart pointer

	// Or with raw pointers, without smart pointers (not recommended)
	SpreadsheetCell* myCellp{ new SpreadsheetCell{ 5 } };
	// Or
	// SpreadsheetCell* myCellp{ new SpreadsheetCell(5) };
	SpreadsheetCell* anotherCellp{ nullptr };
	anotherCellp = new SpreadsheetCell{ 4 };
	// ... do something with the cells
	delete myCellp; 		myCellp = nullptr;
	delete anotherCellp; 	anotherCellp = nullptr;

	SpreadsheetCell aThirdCell{ "test" };  // uses string-arg ctor
	SpreadsheetCell aFourthCell{ 4.4 };    // uses double-arg ctor
	auto aFifthCellp{ make_unique<SpreadsheetCell>("5.5") }; // string-arg ctor
	cout << "aThirdCell: " << aThirdCell.getValue() << endl;
	cout << "aFourthCell: " << aFourthCell.getValue() << endl;
	cout << "aFifthCellp: " << aFifthCellp->getValue() << endl;
}
