package hfdp.ch1;

import cl.mbassale.hfdp.ch1.Duck;
import cl.mbassale.hfdp.ch1.RedheadDuck;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RedheadDuckTest {

    Duck duck;

    @BeforeEach
    void setUp() {
        duck = new RedheadDuck();
    }

    @Test
    void display() {
        assertDoesNotThrow(() -> duck.display());
    }
}