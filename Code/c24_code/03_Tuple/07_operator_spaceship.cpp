import <tuple>;
import <string>;
import <iostream>;

using namespace std;

class Foo
{
public:
	Foo(int i, string s, bool b)
		: m_int{ i }, m_str{ move(s) }, m_bool{ b }
	{
	}

	auto operator<=>(const Foo& rhs)
	{
		return tie(m_int, m_str, m_bool) <=>
			tie(rhs.m_int, rhs.m_str, rhs.m_bool);
	}
private:
	int m_int;
	string m_str;
	bool m_bool;
};

int main()
{
	Foo f1{ 42, "Hello", false };
	Foo f2{ 42, "World", false };
	cout << (f1 < f2) << endl;  // Outputs 1
	cout << (f2 > f1) << endl;  // Outputs 1
}
