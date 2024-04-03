import <unordered_set>;
import <set>;
import <string>;
import <string_view>;

using namespace std;

class Hasher
{
public:
	using is_transparent = void;
	size_t operator()(string_view sv) const { return hash<string_view>{}(sv); }
};

int main()
{
	{
		set<string, less<>> mySet;
		auto i1{ mySet.find("Key") };   // No string constructed, no memory allocated.
		auto i2{ mySet.find("Key"sv) }; // No string constructed, no memory allocated.
	}

	{
		unordered_set<string, Hasher, equal_to<>> mySet;
		auto i1{ mySet.find(string{ "Key" }) };   // No string constructed, no memory allocated.
		auto i2{ mySet.find("Key"sv) };           // No string constructed, no memory allocated.
	}
}