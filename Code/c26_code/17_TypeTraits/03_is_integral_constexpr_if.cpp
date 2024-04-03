import <iostream>;
import <string>;
import <type_traits>;

using namespace std;

template<typename T>
void process(const T& t)
{
	if constexpr (is_integral_v<T>) {
		cout << t << " is an integral type." << endl;
	} else {
		cout << t << " is a non-integral type." << endl;
	}
}

int main()
{
	process(123);
	process(2.2);
	process("Test"s);
}
