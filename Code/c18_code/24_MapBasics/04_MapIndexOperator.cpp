import <map>;
import <iostream>;

using namespace std;

class Data final
{
public:
	explicit Data(int value = 0) : m_value{ value } { }
	int getValue() const { return m_value; }
	void setValue(int value) { m_value = value; }

private:
	int m_value;
};

int main()
{
	map<int, Data> dataMap;
	dataMap[1] = Data{ 4 };
	dataMap[1] = Data{ 6 }; // Replaces the element with key 1
}
