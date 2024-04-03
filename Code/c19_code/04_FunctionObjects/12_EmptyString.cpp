import <vector>;
import <string>;
import <iostream>;
import <functional>;

using namespace std;

template<typename Matcher>
void printMatchingStrings(const vector<string>& strings, Matcher matcher)
{
	for (const auto& string : strings) {
		if (matcher(string)) {
			cout << string << " ";
		}
	}
}

int main()
{
	vector<string> values{ "Hello", "", "", "World", "!" };
	printMatchingStrings(values, not_fn(mem_fn(&string::empty)));
}
