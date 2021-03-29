package hfdp.ch8;

import cl.mbassale.hfdp.ch8.Coffee;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CoffeeTest {

    Coffee coffee;

    @BeforeEach
    void setUp() {
        coffee = new Coffee();
    }

    @Test
    void prepareRecipe() {
        assertDoesNotThrow(() -> coffee.prepareRecipe());
    }
}