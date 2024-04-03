class Bar { };

class Foo
{
public:
	explicit Foo(const Bar& b) {}   //// Pass by reference-to-const.
};

Foo getFoo(bool condition, const Bar& b1, const Bar& b2)  //// Pass by reference-to-const.
{
	//return condition ? Foo{ b1 } : Foo{ b2 };  //// This prohibits RVO.
	
	if (condition) {
		return Foo{ b1 };
	} else {
		return Foo{ b2 };
	}
}

int main()
{
	Bar b1, b2;
	auto foo{ getFoo(true, b1, b2) };
}