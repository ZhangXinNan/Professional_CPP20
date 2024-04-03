import <algorithm>;
import <vector>;
import <iostream>;

using namespace std;

int main()
{
	vector<int> myVector;
	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		int score;
		cin >> score;
		if (score == 0) {
			break;
		}
		myVector.push_back(score);
	}

	auto isPerfectScore{ [tally = 0] (int i) mutable {
		cout << ++tally << endl;  return i >= 100; } };

	auto endIt{ cend(myVector) };
	//auto it{ find_if(cbegin(myVector), endIt, isPerfectScore) };
	auto it{ find_if(cbegin(myVector), endIt, ref(isPerfectScore)) };
	if (it != endIt) { cout << "Found a \"perfect\" score of " << *it << endl; }
	isPerfectScore(1);
}
