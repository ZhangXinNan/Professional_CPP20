#include <cstddef>
import <iostream>;
import <string>;
import <unordered_map>;
import <format>;

using namespace std;

void printMap(const auto& m)  // C++20 abbreviated function template
// If abbreviated function templates are not yet supported by your compiler:
//template<class T>
//void printMap(const T& m)
{
	for (auto& [key, value] : m) {
		cout << format("{} (Phone: {})", key, value) << endl;
	}
	
	// If your compiler doesn't support the C++17 structured bindings
	// yet, then you can use the following for loop.
	//for (auto& p : m) {
	//	cout << p.first << " (Phone: " << p.second << ")" << endl;
	//}

	cout << "-------" << endl;
}

int main()
{
	// Create a hash table.
	unordered_map<string, string> phoneBook{
		{ "Marc G.", "123-456789" },
		{ "Scott K.", "654-987321" } };
	printMap(phoneBook);

	// Add/remove some phone numbers.
	phoneBook.insert(make_pair("John D.", "321-987654"));
	phoneBook["Johan G."] = "963-258147";
	phoneBook["Freddy K."] = "999-256256";
	phoneBook.erase("Freddy K.");
	printMap(phoneBook);

	// Find the bucket index for a specific key.
	const size_t bucket{ phoneBook.bucket("Marc G.") };
	cout << format("Marc G. is in bucket {} containing the following {} names:",
		bucket, phoneBook.bucket_size(bucket)) << endl;
	// Get begin and end iterators for the elements in this bucket.
	// 'auto' is used here. The compiler deduces the type of
	// both as unordered_map<string, string>::const_local_iterator
	auto localBegin{ phoneBook.cbegin(bucket) };
	auto localEnd{ phoneBook.cend(bucket) };
	for (auto iter{ localBegin }; iter != localEnd; ++iter) {
		cout << format("\t{} (Phone: {})", iter->first, iter->second) << endl;
	}
	cout << "-------" << endl;

	// Print some statistics about the hash table
	cout << format("There are {} buckets.", phoneBook.bucket_count()) << endl;
	cout << format("Average number of elements in a bucket is {}.", phoneBook.load_factor()) << endl;
}
