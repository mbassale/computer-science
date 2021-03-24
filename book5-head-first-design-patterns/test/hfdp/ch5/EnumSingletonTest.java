package hfdp.ch5;

import cl.mbassale.hfdp.ch5.EnumSingleton;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EnumSingletonTest {

    @Test
    public void singleton() {
        assertDoesNotThrow(EnumSingleton.INSTANCE::bar);
        assertDoesNotThrow(EnumSingleton.INSTANCE::foo);
    }

}