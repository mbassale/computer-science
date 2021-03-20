package hfdp.ch2;

import cl.mbassale.hfdp.ch2.CurrentConditionsDisplay;
import cl.mbassale.hfdp.ch2.WeatherData;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Random;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

class CurrentConditionsDisplayTest {

    WeatherData weatherData;

    @BeforeEach
    void setUp() {
        weatherData = new WeatherData();
    }

    @Test
    void update() {
        var random = new Random();
        float randomTemperature = random.nextFloat();
        float randomHumidity = random.nextFloat();
        float randomPressure = random.nextFloat();
        var display = new CurrentConditionsDisplay(weatherData) {
            public boolean isCalled = false;

            @Override
            public void update() {
                super.update();
                isCalled = true;
                assertEquals(randomTemperature, weatherData.getTemperature());
                assertEquals(randomHumidity, weatherData.getHumidity());
                assertEquals(randomPressure, weatherData.getPressure());
            }
        };
        weatherData.setMeasurements(randomTemperature, randomHumidity, randomPressure);
        assertTrue(display.isCalled);
    }

    @Test
    void display() {
        var display = new CurrentConditionsDisplay(weatherData) {
            public boolean isCalled = false;

            @Override
            public void display() {
                super.display();
                isCalled = true;
            }
        };
        weatherData.setMeasurements(1.0f, 2.0f, 3.0f);
        assertTrue(display.isCalled);
    }
}