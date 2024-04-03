import <bit>;
import <iostream>;

using namespace std;

int main()
{
	switch (endian::native)
	{
	case endian::little:
		cout << "Native ordering is little-endian." << endl;
		break;
	case endian::big:
		cout << "Native ordering is big-endian." << endl;
		break;
	}
}