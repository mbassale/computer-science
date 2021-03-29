package hfdp.ch8;

import cl.mbassale.hfdp.ch8.CoffeeWithHook;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CoffeeWithHookTest {

    CoffeeWithHook coffeeWithHook;
    CoffeeWithHook coffeeWithHookNoCondiments;

    @BeforeEach
    void setUp() {
        coffeeWithHook = new CoffeeWithHook(true);
        coffeeWithHookNoCondiments = new CoffeeWithHook(false);
    }

    @Test
    void prepareRecipe() {
        assertDoesNotThrow(() -> coffeeWithHook.prepareRecipe());
    }

    @Test
    void prepareRecipeNoCondiments() {
        assertDoesNotThrow(() -> coffeeWithHookNoCondiments.prepareRecipe());
    }
}