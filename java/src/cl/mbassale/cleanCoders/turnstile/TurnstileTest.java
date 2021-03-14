package cl.mbassale.cleanCoders.turnstile;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TurnstileTest extends TurnstileFSM {
    TurnstileFSM fsm;
    String actions = "";

    @BeforeEach
    public void setup() {
        fsm = this;
        fsm.setState(OneCoinTurnstileState.LOCKED);
        actions = "";
    }

    private void assertActions(String expected) {
        assertEquals(expected, actions);
    }

    @Test
    public void normalOperation() throws Exception {
        coin();
        assertActions("U");
        pass();
        assertActions("UL");
        coin();
        assertActions("ULU");
        pass();
        assertActions("ULUL");
    }

    @Test
    public void forcedEntry() {
        pass();
        assertActions("A");
    }

    @Test
    public void doublePayment() {
        coin();
        coin();
        assertActions("UT");
    }

    @Test
    public void manyCoinsThenPass() {
        for (var i = 0; i < 5; i++)
            coin();
        pass();
        assertActions("UTTTTL");
    }

    @Override
    public void alarm() {
        actions += "A";
    }

    @Override
    public void lock() {
        actions += "L";
    }

    @Override
    public void unlock() {
        actions += "U";
    }

    @Override
    public void thankYou() {
        actions += "T";
    }
}
