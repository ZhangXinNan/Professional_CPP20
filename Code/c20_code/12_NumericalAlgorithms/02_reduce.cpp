import <execution>;
import <numeric>;
import <vector>;

using namespace std;

int main()
{
	vector values { 1, 3, 6, 4, 6, 9 };
	double result1{ accumulate(cbegin(values), cend(values), 0.0) };
	double result2{ reduce(execution::par_unseq, cbegin(values), cend(values)) };
}
