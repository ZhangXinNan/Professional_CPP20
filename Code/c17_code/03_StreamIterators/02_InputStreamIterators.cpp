import <iostream>;
import <iterator>;

using namespace std;

// Calculate the sum of all the elements in a given range.
template<typename InputIter>
auto sum(InputIter begin, InputIter end)
{
	auto sum{ *begin };
	for (auto iter{ ++begin }; iter != end; ++iter) {
		sum += *iter;
	}
	return sum;
}

int main()
{
	// Calculate the sum of integers read from the console until the end-of-stream is reached.
	// Note:
	//    On Windows, the end-of-stream is reached when pressing Ctrl+Z followed by Enter.
	//    On Linux, the end-of-stream is reached by pressing enter to get a new line, followed by Ctrl+D.
	cout << "Enter numbers separated by whitespace." << endl;
	cout << "Press Ctrl+Z followed by Enter to stop." << endl;
	istream_iterator<int> numbersIter{ cin };
	istream_iterator<int> endIter;
	int result{ sum(numbersIter, endIter) };
	cout << "Sum: " << result << endl;
}
