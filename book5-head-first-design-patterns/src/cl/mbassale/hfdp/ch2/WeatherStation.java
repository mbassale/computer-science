package cl.mbassale.hfdp.ch2;

public interface WeatherStation {

    float getTemperature();

    float getHumidity();

    float getPressure();

    void measurementsChanged();

    void setMeasurements(float temperature, float humidity, float pressure);
}
