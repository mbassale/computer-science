package hfdp.ch1;

import cl.mbassale.hfdp.ch1.DuckCallDevice;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DuckCallDeviceTest {

    DuckCallDevice duckCallDevice;

    @BeforeEach
    void setUp() {
        duckCallDevice = new DuckCallDevice();
    }

    @Test
    void quack() {
        assertDoesNotThrow(() -> duckCallDevice.quack());
    }
}