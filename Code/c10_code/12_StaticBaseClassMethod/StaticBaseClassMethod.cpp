import <iostream>;

using namespace std;

class BaseStatic
{
public:
	static void beStatic() {
		cout << "BaseStatic being static." << endl;
	}
};

class DerivedStatic : public BaseStatic
{
public:
	static void beStatic() {
		cout << "DerivedStatic keepin' it static." << endl;
	}
};

int main()
{
	{
		BaseStatic::beStatic();
		DerivedStatic::beStatic();
	}

	{
		DerivedStatic myDerivedStatic;
		BaseStatic& ref{ myDerivedStatic };
		myDerivedStatic.beStatic();
		ref.beStatic();
	}
}
