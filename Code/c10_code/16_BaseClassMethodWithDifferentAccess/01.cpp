import <iostream>;

using namespace std;

class Gregarious
{
public:
	virtual void talk() {
		cout << "Gregarious says hi!" << endl;
	}
};

class Shy : public Gregarious
{
protected:
	void talk() override {
		cout << "Shy reluctantly says hello." << endl;
	}
};

int main()
{
	{
		Shy myShy;
		//myShy.talk();  // Error! Attempt to access protected method.
	}

	{
		Shy myShy;
		Gregarious& ref{ myShy };
		ref.talk();
	}
}
