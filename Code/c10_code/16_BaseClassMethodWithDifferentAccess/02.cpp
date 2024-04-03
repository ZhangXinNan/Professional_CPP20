import <iostream>;

using namespace std;

class Secret
{
protected:
	virtual void dontTell() { cout << "I'll never tell." << endl; }
};

class Blabber : public Secret
{
public:
	using Secret::dontTell;
};

int main()
{
	Blabber myBlabber;
	myBlabber.dontTell(); // Outputs "I'll never tell."
}
