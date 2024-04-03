import grid;
import <vector>;
import <deque>;
import <iostream>;
import <optional>;

using namespace std;

int main()
{
	Grid<int, vector<optional<int>>> myIntVectorGrid;
	Grid<int, deque<optional<int>>> myIntDequeGrid;

	myIntVectorGrid.at(3, 4) = 5;
	cout << myIntVectorGrid.at(3, 4).value_or(0) << endl;

	myIntDequeGrid.at(1, 2) = 3;
	cout << myIntDequeGrid.at(1, 2).value_or(0) << endl;

	Grid<int, vector<optional<int>>> grid2{ myIntVectorGrid };
	grid2 = myIntVectorGrid;

	//Grid<int, double> test; // WILL NOT COMPILE
}
