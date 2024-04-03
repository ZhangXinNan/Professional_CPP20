import <algorithm>;
import <vector>;
import <iostream>;

using namespace std;

// Function template to populate a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
	while (true) {
		cout << "Enter a number (0 to quit): ";
		int value;
		cin >> value;
		if (value == 0) {
			break;
		}
		cont.push_back(value);
	}
}

class SumAndProduct
{
public:
	void operator()(int value)
	{
		m_sum += value;
		m_product *= value;
	}

	int getSum() const { return m_sum; }
	int getProduct() const { return m_product; }

private:
	int m_sum{ 0 };
	int m_product{ 1 };
};

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	SumAndProduct calculator;
	calculator = for_each(cbegin(myVector), cend(myVector), calculator);
	cout << "The sum is " << calculator.getSum() << endl;
	cout << "The product is " << calculator.getProduct() << endl;
}
