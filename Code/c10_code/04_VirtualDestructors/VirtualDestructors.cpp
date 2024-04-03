import <iostream>;

using namespace std;

class Base
{
public:
	Base() {}
	~Base() {}
};

class Derived : public Base
{
public:
	Derived()
	{
		m_string = new char[30];
		cout << "m_string allocated" << endl;
	}

	~Derived()
	{
		delete[] m_string;
		cout << "m_string deallocated" << endl;
	}
private:
	char* m_string;
};

int main()
{
	Base* ptr{ new Derived{} };   // m_string is allocated here.
	delete ptr; // ~Base is called, but not ~Derived because the destructor
				// is not virtual!
}
