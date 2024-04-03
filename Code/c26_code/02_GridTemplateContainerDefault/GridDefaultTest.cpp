import grid;
import <vector>;
import <deque>;
import <iostream>;
import <optional>;

using namespace std;

int main()
{
	Grid<int, deque<optional<int>>> myDequeGrid;
	Grid<int, vector<optional<int>>> myVectorGrid;
	Grid<int> myVectorGrid2{ myVectorGrid };
}
