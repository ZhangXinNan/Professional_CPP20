import <iostream>;
import <string>;
import <string_view>;

using namespace std;

void handleValue(int value) { cout << "Integer: " << value << endl; }
void handleValue(double value) { cout << "Double: " << value << endl; }
void handleValue(string_view value) { cout << "String: " << value << endl; }

template<typename... Tn>
void processValues(const Tn&... args)
{
	(handleValue(args), ...);
}

int main()
{
	processValues(1, 2, 3.56, "test", 1.1f);
}