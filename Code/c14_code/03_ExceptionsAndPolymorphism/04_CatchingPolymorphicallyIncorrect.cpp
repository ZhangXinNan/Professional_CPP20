import <fstream>;
import <iostream>;
import <vector>;
import <string>;
import <string_view>;
import <stdexcept>;
import <format>;

using namespace std;

vector<int> readIntegerFile(string_view filename)
{
	ifstream inputStream { filename.data() };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		const string error{ format("Unable to open file {}.", filename.data()) };
		throw invalid_argument{ error };
	}

	// Read the integers one-by-one and add them to a vector.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}

	if (!inputStream.eof()) {
		// We did not reach the end-of-file.
		// This means that some error occurred while reading the file.
		// Throw an exception.
		const string error{ format("Unable to read file {}.", filename.data()) };
		throw runtime_error{ error };
	}

	return integers;
}

int main()
{
	const string filename{ "IntegerFile.txt" };
	vector<int> myInts;

	try {
		myInts = readIntegerFile(filename);
	} catch (const exception& e) { // BUG: catching base class first!
		cerr << e.what() << endl;
		return 1;
	} catch (const invalid_argument& /* e */) {
		// Take some special action for invalid filenames.
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;
}
