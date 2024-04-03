import <string>;
import <vector>;
import <iostream>;

using namespace std;

void removeEmptyStrings(vector<string>& strings)
{
	erase_if(strings, [](const string& str) { return str.empty(); });
}

int main()
{
	vector<string> myVector{ "", "one", "", "two", "three", "four" };

	for (auto& str : myVector) { cout << "\"" << str << "\"  "; }
	cout << endl;
	removeEmptyStrings(myVector);
	for (auto& str : myVector) { cout << "\"" << str << "\"  "; }
	cout << endl;
}
