import <iostream>;
import <string>;

using namespace std;

class TextHolder
{
public:
	TextHolder(string text) : m_text{ move(text) } {}
	
	//const string& getText() const { return m_text; }
	
	const string& getText() const & { return m_text; }
	string&& getText() && { return move(m_text); }

private:
	string m_text;
};

int main()
{
	TextHolder textHolder{ "Hello world!" };
	cout << textHolder.getText() << endl;
	cout << TextHolder{ "Hello world!" }.getText() << endl;
	cout << move(textHolder).getText() << endl;
}
