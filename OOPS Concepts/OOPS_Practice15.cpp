/*In a weather monitoring application, you have a `WeatherData` class that keeps
track of temperature and humidity. Write a function `updateWeatherData` that accepts
the temperature and humidity values by reference and updates the class attributes
accordingly. Show the effects of using call by reference versus call by value by
attempting to update the data from the main function. */
#include <iostream>
using namespace std;

class WeatherData {
    private:
    float temperature;
    float humidity;

    public:
    WeatherData(float temp, float hum) : temperature(temp), humidity(hum) {}
        void displayWeatherData() const {
        cout << "Temperature: " << temperature << "°C" << endl;
        cout << "Humidity: " << humidity << "%" << endl;
    }

    void updateWeatherData(float &temp, float &hum) {
        temperature = temp;
        humidity = hum;
    }

    void updateWeatherDataByValue(float temp, float hum) {
        temperature = temp;
        humidity = hum;
    }
};

int main() {
    WeatherData weather(25.5, 65.0);
    cout << "Initial Weather Data:" << endl;
    weather.displayWeatherData();
    float newTemperature = 30.0;
    float newHumidity = 70.0;
    cout << "\nValues before update (Call by Reference):" << endl;
    cout << "newTemperature: " << newTemperature << "°C, newHumidity: " << newHumidity << "%" <<
    endl;
    weather.updateWeatherData(newTemperature, newHumidity);
    cout << "Values after update (Call by Reference):" << endl;
    cout << "newTemperature: " << newTemperature << "°C, newHumidity: " << newHumidity << "%" <<
    endl;
    cout << "\nWeather Data after Call by Reference:" << endl;
    weather.displayWeatherData();
    newTemperature = 28.0;
    newHumidity = 80.0;
    cout << "\nValues before update (Call by Value):" << endl;
    cout << "newTemperature: " << newTemperature << "°C, newHumidity: " << newHumidity << "%" <<
    endl;
    weather.updateWeatherDataByValue(newTemperature, newHumidity);
    cout << "Values after update (Call by Value):" << endl;
    cout << "newTemperature: " << newTemperature << "°C, newHumidity: " << newHumidity << "%" <<
    endl;
    cout << "\nWeather Data after Call by Value (No Change):" << endl;
    weather.displayWeatherData();
    return 0;
}