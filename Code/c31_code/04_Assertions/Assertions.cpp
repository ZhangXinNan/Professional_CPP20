#include <cassert>
import <vector>;

using namespace std;

void process(const vector<int>& coordinate)
{
	assert(("A custom message...", coordinate.size() == 3));
	
	//assert(!"This should never happen.");
	
	// ...
}

int main()
{
	process({ 1, 2, 3 });
	process({ 1, 2 });
}
