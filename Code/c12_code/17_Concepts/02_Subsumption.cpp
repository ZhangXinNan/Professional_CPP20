import <iostream>;
import <concepts>;

using namespace std;

template <typename T> requires integral<T>
void process(const T& t) { cout << "integral<T>" << endl; }

template <typename T> requires (integral<T> && sizeof(T) == 4)
void process(const T& t) { cout << "integral<T> && sizeof(T) == 4" << endl; }

int main()
{
	process(int{ 1 });
	process(short{ 2 });
}