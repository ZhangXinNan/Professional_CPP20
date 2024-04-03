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
void callDoit(const T& [[maybe_unused]] t)
{
	if constexpr (is_base_of_v<IsDoable, T>) {
		t.doit();
	} else {
		cout << "Cannot call doit()!" << endl;
	}
}

int main()
{
	Derived d;
	callDoit(d);
	callDoit(123);
}
