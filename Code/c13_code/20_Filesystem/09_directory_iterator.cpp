#include <cstddef>
import <filesystem>;
import <iostream>;
import <format>;

using namespace std;
using namespace std::filesystem;

void printDirectoryStructure(const path& p, size_t level = 0)
{
	if (!exists(p)) {
		return;
	}

	const string spacer(level * 2, ' ');

	if (is_regular_file(p)) {
		cout << format("{}File: {} ({} bytes)",
			spacer, p.string(), file_size(p)) << endl;
	} else if (is_directory(p)) {
		cout << format("{}Dir: {}", spacer, p.string()) << endl;
		for (auto& entry : directory_iterator{ p }) {
			printDirectoryStructure(entry, level + 1);
		}
	}
}

int main()
{
	path p{ R"(D:\Foo\Bar)" };
	printDirectoryStructure(p);
}
