import <iostream>;
import <type_traits>;

using namespace std;

class IsDoable
{
public:
	virtual void doit() const { cout << "IsDoable::doit()" << endl; }
};

class Derived : public IsDoable
{
};

template<typename T>
enable_if_t<is_base_of_v<IsDoable, T>, void>
	callDoit(const T& t)
{
	t.doit();
}

template<typename T>
enable_if_t<!is_base_of_v<IsDoable, T>, void>
	callDoit(const T&)
{
	cout << "Cannot call doit()!" << endl;
}

int main()
{
	Derived d;
	callDoit(d);
	callDoit(123);
}
