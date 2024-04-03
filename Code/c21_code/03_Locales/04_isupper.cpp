import <iostream>;
import <locale>;

using namespace std;

int main()
{
	bool result{ isupper('É', locale{ "fr-FR" }) };
	cout << result << endl;
}
