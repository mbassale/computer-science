package hfdp.ch2;

import cl.mbassale.hfdp.ch2.Observer;
import cl.mbassale.hfdp.ch2.WeatherData;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Random;

import static org.junit.jupiter.api.Assertions.*;

class WeatherDataTest {

    WeatherData weatherData;

    private static class TrackingObserver implements Observer {

        public boolean isCalled = false;

        @Override
        public void update() {
            isCalled = true;
        }
    }

    @BeforeEach
    void setUp() {
        weatherData = new WeatherData();
    }

    @Test
    void registerObserver() {
        var observer = new TrackingObserver() {
            @Override
            public void update() {
                super.update();
                assertEquals(1.0f, weatherData.getTemperature());
                assertEquals(2.0f, weatherData.getHumidity());
                assertEquals(3.0f, weatherData.getPressure());
            }
        };
        weatherData.registerObserver(observer);
        weatherData.setMeasurements(1.0f, 2.0f, 3.0f);
        assertTrue(observer.isCalled);
    }

    @Test
    void removeObserver() {
        var observer = new TrackingObserver() {
            @Override
            public void update() {
                super.update();
                fail();
            }
        };
        weatherData.registerObserver(observer);
        weatherData.removeObserver(observer);
        weatherData.setMeasurements(1.0f, 2.0f, 3.0f);
    }

    @Test
    void notifyObservers() {
        var observer1 = new TrackingObserver();
        weatherData.registerObserver(observer1);
        var observer2 = new TrackingObserver();
        weatherData.registerObserver(observer2);
        assertFalse(observer1.isCalled);
        assertFalse(observer2.isCalled);
        weatherData.setMeasurements(1.0f, 2.0f, 3.0f);
    }

    @Test
    void measurementsChanged() {
        var observer1 = new TrackingObserver();
        weatherData.registerObserver(observer1);
        var observer2 = new TrackingObserver();
        weatherData.registerObserver(observer2);
        weatherData.measurementsChanged();
        assertTrue(observer1.isCalled);
        assertTrue(observer2.isCalled);
    }

    @Test
    void setMeasurements() {
        Random random = new Random();
        float randomTemp = random.nextFloat();
        float randomHumidity = random.nextFloat();
        float randomPressure = random.nextFloat();
        var observer1 = new TrackingObserver() {
            @Override
            public void update() {
                super.update();
                assertEquals(randomTemp, weatherData.getTemperature());
                assertEquals(randomHumidity, weatherData.getHumidity());
                assertEquals(randomPressure, weatherData.getPressure());
            }
        };
        weatherData.registerObserver(observer1);
        weatherData.setMeasurements(randomTemp, randomHumidity, randomPressure);
        assertTrue(observer1.isCalled);
    }
}