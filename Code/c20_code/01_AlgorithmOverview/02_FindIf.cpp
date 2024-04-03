import <algorithm>;
import <vector>;
import <iostream>;

using namespace std;

bool perfectScore(int num)
{
	return num >= 100;
}

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

	auto endIt{ cend(myVector) };
	auto it{ find_if(cbegin(myVector), endIt, perfectScore) };
	if (it == endIt) {
		cout << "No perfect scores" << endl;
	} else {
		cout << "Found a \"perfect\" score of " << *it << endl;
	}
}
