import <iostream>;
import <string>;

using namespace std;

class Person
{
public:
	Person();
	Person(string firstName, string lastName, int age);
	Person(const Person& rhs);
	virtual ~Person();

	const string& getFirstName() const { return m_firstName; }
	const string& getLastName() const { return m_lastName; }
	int getAge() const { return m_age; }

private:
	string m_firstName, m_lastName;
	int m_age{ 0 };
};

Person::Person()
{
	cout << "Default Ctor" << endl;
}

Person::Person(string firstName, string lastName, int age)
	: m_firstName{ move(firstName) }, m_lastName{ move(lastName) }, m_age{ age }
{
	cout << "Ctor" << endl;
}

Person::~Person()
{
	cout << "dtor" << endl;
}

Person::Person(const Person& rhs)
	: m_firstName{ rhs.m_firstName }, m_lastName{ rhs.m_lastName }, m_age{ rhs.m_age }
{
	cout << "Copy ctor" << endl;
}

ostream& operator<<(ostream& ostr, const Person& p)
{
	ostr << p.getFirstName() << " " << p.getLastName() <<
		" " << p.getAge() << endl;

	return ostr;
}


/*
void processPerson(Person p)
{
// process the person
}
*/


void processPerson(const Person& /*p*/)
{
	// process the person
}

Person createPerson()
{
	Person newP;
	return newP;
}

int main()
{
	Person me{ "Marc", "Gregoire", 42 };
	processPerson(me);
	
	cout << "-----" << endl;

	cout << createPerson();

	cout << "-----" << endl;

	createPerson();
}
