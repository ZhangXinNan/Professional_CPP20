import <filesystem>;
import <iostream>;

using namespace std;
using namespace std::filesystem;

int main()
{
	space_info s{ space("c:\\") };
	cout << "Capacity: " << s.capacity << endl;
	cout << "Free: " << s.free << endl;
}
