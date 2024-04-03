import <iostream>;
import <initializer_list>;
import <stdexcept>;
import <vector>;

using namespace std;

class EvenSequence
{
public:
	EvenSequence(initializer_list<double> args)
	{
		if (args.size() % 2 != 0) {
			throw invalid_argument{ "initializer_list should "
				"contain even number of elements." };
		}
		m_sequence.reserve(args.size());
		for (const auto& value : args) {
			m_sequence.push_back(value);
		}
		// Or:
		// m_sequence.assign(args);
	}

	void dump() const
	{
		for (const auto& value : m_sequence) {
			cout << value << ", ";
		}
		cout << endl;
	}

private:
	vector<double> m_sequence;
};

int main()
{
	EvenSequence p1 { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	p1.dump();

	try {
		EvenSequence p2 { 1.0, 2.0, 3.0 };
	} catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
}