import spreadsheet;
import <iostream>;

using namespace std;

int main()
{
	SpreadsheetApplication app;
	Spreadsheet s1 { 2, 3, app };
	Spreadsheet s2 { 3, 4, app };

	cout << "Maximum height is: " << Spreadsheet::MaxHeight << endl;
}
