import pointer;
import spreadsheet_cell;
import <iostream>;

using namespace std;

void testConst(const Pointer<int>& p)
{
	cout << *p;
	// *p = 7;
}

void TestConstTwo(const Pointer<SpreadsheetCell>& /*p*/)
{
	// p->set(5);
}

int main()
{
	Pointer<int> smartInt{ new int };
	*smartInt = 5; // Dereference the smart pointer.
	cout << *smartInt << endl;

	Pointer<SpreadsheetCell> smartCell{ new SpreadsheetCell };
	smartCell->set(5); // Dereference and member select the set() method.
	cout << smartCell->getValue() << endl;
}
