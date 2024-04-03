import <iostream>;
import <sstream>;

using namespace std;

int main()
{
	cout << "Enter tokens. "
		<< "Control+D (Unix) or Control+Z (Windows) followed by Enter to end." << endl;

	ostringstream outStream;

	while (cin) {
		string nextToken;

		cout << "Next token: ";
		cin >> nextToken;

		if (!cin || nextToken == "done")
			break;

		outStream << nextToken << "\t";
	}

	cout << "The end result is: " << outStream.str();
}
