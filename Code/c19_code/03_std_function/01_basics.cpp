import <iostream>;
import <functional>;
import <format>;
import <string_view>;

using namespace std;

void func(int num, string_view str)
{
	cout << format("func({}, {})", num, str) << endl;
}

int main()
{
	//function<void(int, string_view)> f1{ func };

	// With class template argument deduction
	function f1{ func };

	f1(1, "test");
}
