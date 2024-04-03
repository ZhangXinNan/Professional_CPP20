import <iterator>;
import <vector>;
import <format>;
import <iostream>;

using namespace std;

template<typename Iter>
auto myFind(Iter begin, Iter end, const typename iterator_traits<Iter>::value_type& value)
{
	for (auto iter{ begin }; iter != end; ++iter) {
		if (*iter == value) {
			return iter;
		}
	}
	return end;
}

int main()
{
	vector values{ 11, 22, 33, 44 };

	auto result{ myFind(cbegin(values), cend(values), 22) };
	if (result != cend(values)) {
		cout << format("Found value at position {}", distance(cbegin(values), result));
	}
}