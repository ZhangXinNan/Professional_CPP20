import <iostream>;
import spreadsheet;
import invalid_coordinate;

using namespace std;

int main()
{
	try {
		Spreadsheet s{ 100, 256 };
	} catch (const exception& caughtException) {
		cerr << caughtException.what() << endl;
	}

	try {
		Spreadsheet s{ 49, 49 };
		auto& cell = s.getCellAt(55, 55);
	} catch (const exception& caughtException) {
		cerr << caughtException.what() << endl;
	}

	try {
		Spreadsheet s{ 49, 49 };
		s.setCellAt(55, 55, SpreadsheetCell{ 1.2 });
	}
	catch (const exception& caughtException) {
		cerr << caughtException.what() << endl;
	}
}
