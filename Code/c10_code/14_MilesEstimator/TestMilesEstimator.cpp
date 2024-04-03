import efficient_car_miles_estimator;
import <iostream>;
import <format>;

using namespace std;

int main()
{
	MilesEstimator myMilesEstimator;
	myMilesEstimator.setGallonsLeft(2);
	cout << format("Normal estimator can go {} more miles.",
		myMilesEstimator.getMilesLeft()) << endl;

	EfficientCarMilesEstimator myEstimator;
	myEstimator.setGallonsLeft(2);
	cout << format("Efficient estimator can go {} more miles.",
		myEstimator.getMilesLeft()) << endl;
}
