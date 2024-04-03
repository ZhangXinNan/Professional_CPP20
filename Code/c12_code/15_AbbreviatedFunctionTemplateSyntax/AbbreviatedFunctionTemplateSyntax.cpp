import <iostream>;

decltype(auto) add(const auto& t1, const auto& t2)
{
	return t1 + t2;
}

int main()
{
	std::cout << add(2, 4) << std::endl;
}
