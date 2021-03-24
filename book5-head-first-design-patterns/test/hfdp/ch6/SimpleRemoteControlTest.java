package hfdp.ch6;

import cl.mbassale.hfdp.ch6.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SimpleRemoteControlTest {

    SimpleRemoteControl simpleRemoteControl;

    @BeforeEach
    void setUp() {
        simpleRemoteControl = new SimpleRemoteControl();
    }

    @Test
    void lightOnCommand() {
        var light = new Light();
        var lightOn = new LightOnCommand(light);
        simpleRemoteControl.setCommand(lightOn);
        assertDoesNotThrow(() -> simpleRemoteControl.buttonWasPressed());
    }

    @Test
    void garageDoorCommand() {
        var garageDoor = new GarageDoor();
        var garageOpen = new GarageDoorOpenCommand(garageDoor);
        simpleRemoteControl.setCommand(garageOpen);
        assertDoesNotThrow(() -> simpleRemoteControl.buttonWasPressed());
    }
}