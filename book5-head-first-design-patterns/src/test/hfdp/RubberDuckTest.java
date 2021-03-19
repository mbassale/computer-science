package hfdp;

import cl.mbassale.hfdp.ch1.Duck;
import cl.mbassale.hfdp.ch1.RubberDuck;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RubberDuckTest {

    Duck duck;

    @BeforeEach
    void setUp() {
        duck = new RubberDuck();
    }

    @Test
    void display() {
        assertDoesNotThrow(() -> duck.display());
    }
}