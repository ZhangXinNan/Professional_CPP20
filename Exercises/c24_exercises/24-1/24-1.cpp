import <iostream>;
import <variant>;
import <vector>;
import <string>;

using namespace std;

class Error
{
public:
	Error(string message) : m_message{ move(message) } { }
	const string& getMessage() const { return m_message; }

private:
	string m_message;
};

variant<vector<int>, Error> getData(bool fail)
{
	if (fail) {
		return Error{ "An error occured." };
	} else {
		return vector{ 11,22,33 };
	}
}

void handleResult(const variant<vector<int>, Error>& result)
{
	if (holds_alternative<Error>(result)) {
		cout << "Error: " << get<Error>(result).getMessage() << endl;
	} else {
		auto& data{ get<vector<int>>(result) };
		for (auto& value : data) {
			cout << value << " ";
		}
		cout << endl;
	}
}

int main()
{
	handleResult(getData(false));
	handleResult(getData(true));
}
