#include <cstdio>
import <iostream>;
import <memory>;

using namespace std;

void close(FILE* filePtr)
{
	if (filePtr == nullptr) { return; }
	fclose(filePtr);
	cout << "File closed." << endl;
}

int main()
{
#if defined(_MSC_VER)
	// Using Microsoft Visual C++
	FILE* f{ nullptr };
	fopen_s(&f, "data.txt", "w");
#else
	FILE* f{ fopen("data.txt", "w") };
#endif
	shared_ptr<FILE> filePtr{ f, close };
	if (filePtr == nullptr) {
		cerr << "Error opening file." << endl;
	} else {
		cout << "File opened." << endl;
		// Use filePtr
	}
}
