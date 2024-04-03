import key_value_pair;
import <iostream>;
import <string>;
import <format>;

using namespace std;

int main()
{
	KeyValuePair<int, double> kv1{ 11, 2.33 };
	cout << format("{} = {}\n", kv1.getKey(), kv1.getValue());

	KeyValuePair kv2{ "John Doe"s, 123456 };
	cout << format("{} = {}\n", kv2.getKey(), kv2.getValue());

	KeyValuePair<int, const char*> kv3{ 123, "New York" };
	cout << format("{} = {}\n", kv3.getKey(), kv3.getValue());
}
