package hfdp.ch8;

import cl.mbassale.hfdp.ch8.Tea;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TeaTest {

    Tea tea;

    @BeforeEach
    void setUp() {
        tea = new Tea();
    }

    @Test
    void prepareRecipe() {
        assertDoesNotThrow(() -> tea.prepareRecipe());
    }
}