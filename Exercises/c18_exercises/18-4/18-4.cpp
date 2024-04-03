import <vector>;
import <array>;
import <span>;
import <iostream>;

using namespace std;

double average(span<const double> values)
{
	double sum{ 0.0 };
	for (auto& value : values) {
		sum += value;
	}
	return sum / values.size();
}

int main()
{
	vector values1{ 1.1, 2.2, 3.3, 4.4 };
	cout << average(values1) << endl;

	array<double, 4> values2{ 1.1, 2.2, 3.3, 4.4 };
	cout << average(values2) << endl;
	cout << average({ values2.data() + 2, 2 }) << endl;
}
