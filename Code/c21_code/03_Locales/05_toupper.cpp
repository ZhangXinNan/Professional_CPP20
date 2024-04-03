import <iostream>;
import <locale>;

using namespace std;

int main()
{
	auto upper{ toupper('é', locale{ "fr-FR" }) };
}
