package hfdp.ch11;

import cl.mbassale.hfdp.ch11.GumballMachine;
import cl.mbassale.hfdp.ch11.GumballMonitor;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GumballMonitorTest {

    @Test
    void report() {
        GumballMachine gumballMachine = new GumballMachine("TestDrive", 112);
        GumballMonitor monitor = new GumballMonitor(gumballMachine);
        assertDoesNotThrow(monitor::report);
    }
}