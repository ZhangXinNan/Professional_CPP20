import <iostream>;
import <sstream>;
import <string>;

using namespace std;

class Muffin
{
public:
	virtual ~Muffin() = default;

	const string& getDescription() const { return m_description; }
	void setDescription(string description) { m_description = std::move(description); }

	int getSize() const { return m_size; }
	void setSize(int size) { m_size = size; }

	bool hasChocolateChips() const { return m_hasChocolateChips; }
	void setHasChocolateChips(bool hasChips) { m_hasChocolateChips = hasChips; }

	void output() const
	{
		printf("%s, Size is %d, %s\n", getDescription().data(), getSize(),
			(hasChocolateChips() ? "has chips" : "no chips"));
	}

private:
	string m_description;
	int m_size{ 0 };
	bool m_hasChocolateChips{ false };
};


Muffin createMuffin(istringstream& inStream);

int main()
{
	cout << "First, let's create a muffin in code and output it." << endl;

	Muffin myMuffin;
	myMuffin.setDescription("Giant_Blueberry_Muffin");
	myMuffin.setSize(42);
	myMuffin.setHasChocolateChips(false);

	printf("The muffin is ");
	myMuffin.output();
	printf(" -- yummy!\n");


	cout << "Now we'll create a muffin from a string stream" << endl;

	istringstream instream{ "My_Muffin 2 true" };
	Muffin m2{ createMuffin(instream) };
	m2.output();
}

Muffin createMuffin(istringstream& stream)
{
	Muffin muffin;
	// Assume data is properly formatted:
	// Description size chips

	string description;
	int size;
	bool hasChips;

	// Read all three values. Note that chips is represented
	// by the strings "true" and "false"
	stream >> description >> size >> boolalpha >> hasChips;
	if (stream) { // Reading was successful.
		muffin.setSize(size);
		muffin.setDescription(description);
		muffin.setHasChocolateChips(hasChips);
	}

	return muffin;
}
