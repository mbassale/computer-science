package hfdp;

import cl.mbassale.hfdp.ch1.Duck;
import cl.mbassale.hfdp.ch1.MallardDuck;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

class MallardDuckTest {

    private Duck duck;

    @BeforeEach
    void setUp() {
        duck = new MallardDuck();
    }

    @Test
    void display() {
        assertDoesNotThrow(() -> duck.display());
    }
}