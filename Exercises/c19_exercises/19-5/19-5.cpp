import <functional>;
import <iostream>;

using namespace std;

class Processor
{
public:
	using Callback = function<int(int)>;

	Processor(Callback callback)
		: m_callback{ callback }
	{
	}

	int operator()(int value) const
	{
		return m_callback(value);
	}

private:
	Callback m_callback;
};


int square(int value) { return value * value; }
int cube(int value) { return value * value * value; }


int main()
{
	{
		Processor processor{ square };
		cout << processor(2) << endl;
	}

	{
		Processor processor{ cube };
		cout << processor(2) << endl;
	}
}
