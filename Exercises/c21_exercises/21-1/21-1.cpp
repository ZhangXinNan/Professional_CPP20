import <iostream>;
import <locale>;

using namespace std;

int main()
{
	locale userLocale{ "" };
	auto& facet{ use_facet<numpunct<char>>(userLocale) };
	cout << "Decimal separator: " << facet.decimal_point() << endl;
}