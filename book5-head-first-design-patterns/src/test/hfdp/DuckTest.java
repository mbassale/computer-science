package hfdp;

import cl.mbassale.hfdp.ch1.Duck;
import cl.mbassale.hfdp.ch1.behavior.FlyRocketPowered;
import cl.mbassale.hfdp.ch1.behavior.QuackRecorded;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

class DuckTest {

    Duck duck;

    @BeforeEach
    void setUp() {
        duck = new Duck() {
            @Override
            public void display() {
                System.out.println("Abstract duck display.");
            }
        };
    }

    @Test
    void display() {
        assertDoesNotThrow(() -> duck.display());
    }

    @Test
    void swim() {
        assertDoesNotThrow(() -> duck.swim());
    }

    @Test
    void quack() {
        assertDoesNotThrow(() -> duck.quack());
    }

    @Test
    void fly() {
        assertDoesNotThrow(() -> duck.fly());
    }

    @Test
    void setFlyBehavior() {
        assertDoesNotThrow(() -> duck.fly());
        duck.setFlyBehavior(new FlyRocketPowered());
        assertDoesNotThrow(() -> duck.fly());
    }

    @Test
    void setQuackBehavior() {
        assertDoesNotThrow(() -> duck.quack());
        duck.setQuackBehavior(new QuackRecorded());
        assertDoesNotThrow(() -> duck.quack());
    }
}