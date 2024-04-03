import <iostream>;
import <string>;
import <string_view>;

using namespace std;

string encrypt(string_view input);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " string-to-be-encrypted" << endl;
		return -1;
	}

	cout << encrypt(argv[1]);
} 

// Performs a very weak form of "encryption" by 
// adding 13 to each character of the string.
string encrypt(string_view input)
{
	string encrypted{ input.data() };
	for (auto& character : encrypted) {
		character += 13;
	}
	return encrypted;
}
