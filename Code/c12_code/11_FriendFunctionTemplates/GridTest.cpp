import grid;
import <iostream>;

using namespace std;

template<typename T>
void fillGrid(Grid<T>& grid)
{
	T index{ 0 };
	for (size_t y{ 0 }; y < grid.getHeight(); ++y) {
		for (size_t x{ 0 }; x < grid.getWidth(); ++x) {
			grid.at(x, y) = ++index;
		}
	}
}

template<typename T>
void printGrid(const Grid<T>& grid)
{
	for (size_t y{ 0 }; y < grid.getHeight(); ++y) {
		for (size_t x{ 0 }; x < grid.getWidth(); ++x) {
			const auto& element{ grid.at(x, y) };
			if (element.has_value())
				cout << element.value() << '\t';
			else
				cout << "n/a" << '\t';
		}
		cout << endl;
	}
}

int main()
{
	Grid<int> grid1{ 2, 2 };
	Grid<int> grid2{ 3, 3 };

	fillGrid(grid1);
	fillGrid(grid2);

	printGrid(grid1);
	cout << endl;
	printGrid(grid2);
	cout << endl;

	auto result{ grid1 + grid2 };

	printGrid(result);
	cout << endl;
}
