import <iostream>;

// C++14: using automatic function return type deduction
template<typename T1, typename T2>
auto add(const T1& t1, const T2& t2)
{
	return t1 + t2;
}

// C++14: using decltype(auto)
//template<typename T1, typename T2>
//decltype(auto) add(const T1& t1, const T2& t2)
//{
//	return t1 + t2;
//}

// Using the alternative function syntax
//template<typename T1, typename T2>
//auto add(const T1& t1, const T2& t2) -> decltype(t1 + t2)
//{
//	return t1 + t2;
//}

int main()
{
	std::cout << add(2, 4) << std::endl;
}
