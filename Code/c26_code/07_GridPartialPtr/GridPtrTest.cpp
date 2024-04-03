import grid;
import <iostream>;
import <memory>;

using namespace std;

int main()
{
	Grid<int> myIntGrid;       // Uses the non-specialized grid.
	Grid<int*> psGrid{ 2, 2 }; // Uses the partial specialization for pointer types.

	psGrid.at(0, 0) = make_unique<int>(1);
	psGrid.at(0, 1) = make_unique<int>(2);
	psGrid.at(1, 0) = make_unique<int>(3);

	Grid<int*> psGrid2{ psGrid };
	Grid<int*> psGrid3;
	psGrid3 = psGrid2;

	auto& element{ psGrid2.at(1, 0) };
	if (element) {
		cout << *element << endl;
		*element = 6;
	}
	cout << *psGrid.at(1, 0) << endl;  // psGrid is not modified.
	cout << *psGrid2.at(1, 0) << endl; // psGrid2 is modified.
}
