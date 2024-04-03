module my_weather_prediction; 

import <iostream>;
import <format>;

using namespace std;

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
	int fahrenheitTemp{ convertCelsiusToFahrenheit(temp) };
	setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	int fahrenheitTemp{ getTomorrowTempFahrenheit() };
	return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
	cout << format("Tomorrow will be {} degrees Celsius ({} degrees Fahrenheit)",
		getTomorrowTempCelsius(), getTomorrowTempFahrenheit()) << endl;

	cout << format("Chance of rain is {}%", getChanceOfRain() * 100) << endl;

	if (getChanceOfRain() > 0.5) {
		cout << "Bring an umbrella!" << endl;
	}
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius)
{
	return static_cast<int>((9.0 / 5.0) * celsius + 32);
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit)
{
	return static_cast<int>((5.0 / 9.0) * (fahrenheit - 32));
}

string MyWeatherPrediction::getTemperature() const
{
	// Add °F to the string.
	// Note: \u00B0 is the ISO/IEC 10646 representation of the degree symbol.
	return WeatherPrediction::getTemperature() + "\u00B0F";
}
