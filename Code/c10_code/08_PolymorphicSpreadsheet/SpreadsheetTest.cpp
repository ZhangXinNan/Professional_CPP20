import <iostream>;
import <vector>;
import <memory>;
import <format>;
import <string>;
import double_spreadsheet_cell;
import string_spreadsheet_cell;

using namespace std;

int main()
{
	vector<unique_ptr<SpreadsheetCell>> cellArray;

	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<DoubleSpreadsheetCell>());

	cellArray[0]->set("hello");
	cellArray[1]->set("10");
	cellArray[2]->set("18");

	cout << format("Vector: [{},{},{}]", cellArray[0]->getString(),
		cellArray[1]->getString(),
		cellArray[2]->getString()) << endl;

	DoubleSpreadsheetCell myDbl;
	myDbl.set(8.4);
	StringSpreadsheetCell result{ myDbl + myDbl };
	cout << endl << result.getString() << endl;
}
