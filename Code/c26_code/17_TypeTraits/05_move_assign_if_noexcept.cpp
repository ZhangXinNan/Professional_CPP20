import <iostream>;
import <type_traits>;

using namespace std;

template <typename T>
constexpr conditional_t<is_nothrow_move_assignable_v<T>, T&&, const T&>
move_assign_if_noexcept(T& t) noexcept
{
	return move(t);
}

class MoveAssignable
{
public:
	MoveAssignable& operator=(const MoveAssignable&) {
		cout << "copy assign" << endl;
		return *this;
	}
	MoveAssignable& operator=(MoveAssignable&&) {
		cout << "move assign" << endl;
		return *this;
	}
};

class MoveAssignableNoexcept
{
public:
	MoveAssignableNoexcept& operator=(const MoveAssignableNoexcept&) {
		cout << "copy assign" << endl;
		return *this;
	}
	MoveAssignableNoexcept& operator=(MoveAssignableNoexcept&&) noexcept {
		cout << "move assign" << endl;
		return *this;
	}
};

int main()
{
	MoveAssignable a, b;
	a = move_assign_if_noexcept(b);
	MoveAssignableNoexcept c, d;
	c = move_assign_if_noexcept(d);
}
