package hfdp.ch1;

import cl.mbassale.hfdp.ch1.DecoyDuck;
import cl.mbassale.hfdp.ch1.Duck;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

class DecoyDuckTest {

    Duck duck;

    @BeforeEach
    void setUp() {
        duck = new DecoyDuck();
    }

    @Test
    void display() {
        assertDoesNotThrow(() -> duck.display());
    }
}