import spreadsheet;

using namespace std;

int main()
{
	SpreadsheetApplication theApp;
	Spreadsheet s1 { theApp };
	Spreadsheet s3 { theApp, 5, 6 };
	Spreadsheet s4 { s3 };
	s1 = s4;
	s1 = move(s3);
}
