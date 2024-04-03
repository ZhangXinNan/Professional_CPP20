import <unordered_map>;
import <string>;
import <iostream>;

using namespace std;

int main()
{
	unordered_map<string, int> myArray;
	myArray["Key 1"] = 11;
	myArray["Key 2"] = 22;
	myArray["Key 3"] = 33;

	cout << myArray["Key 1"] << endl;
	cout << myArray["Key 2"] << endl;

	//// std::unordered_map does not support operator[]
	//// on const instances.
	// Test const operator[]
	//const AssociativeArray<int>& c{ myArray };
	//cout << c["Key 3"] << endl;
	//cout << c["Key 4"] << endl;

	//// Instead, you can use find().
	const auto& c{ myArray };
	cout << c.find("Key 3")->second << endl;
	auto res{ c.find("Key 4") };
	if (res == end(c)) {
		cout << "Key 4 not found." << endl;
	}
}
