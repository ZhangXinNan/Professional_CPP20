import <vector>;
import <iostream>;

using namespace std;

template<typename Iter>
void myPrint(Iter begin, Iter end)
{
	for (auto iter{ begin }; iter != end; ++iter) {
		cout << *iter << " ";
	}
}

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (auto iter{ cbegin(values) }; iter != cend(values); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	myPrint(cbegin(values), cend(values));
	cout << endl;
}