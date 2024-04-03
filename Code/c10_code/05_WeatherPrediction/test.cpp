import my_weather_prediction;
import <iostream>;

using namespace std;

int main()
{
	MyWeatherPrediction p;
	p.setCurrentTempCelsius(33);
	p.setPositionOfJupiter(80);
	p.showResult();
	cout << p.getTemperature() << endl;
}
