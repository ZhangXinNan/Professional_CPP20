import grid;
import <iostream>;

using namespace std;

constexpr size_t getHeight()
{
	return 10;
}

int main()
{
	Grid<int, 10, 10> myGrid;
	Grid<int, 10, 10> anotherGrid;

	myGrid.at(2, 3) = 42;
	anotherGrid = myGrid;

	cout << anotherGrid.at(2, 3).value_or(0);

	Grid<double, 2, getHeight()> myDoubleGrid;
}
