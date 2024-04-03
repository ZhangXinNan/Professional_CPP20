import spreadsheet_cell;
import <iostream>;

using namespace std;

int main()
{
	SpreadsheetCell cell{ 1.23 };
	
	double d1{ cell };
	cout << d1 << endl;

	string str1 = cell;
	cout << str1 << endl;

	string str2{ static_cast<string>(cell) };
	cout << str2 << endl;
}
