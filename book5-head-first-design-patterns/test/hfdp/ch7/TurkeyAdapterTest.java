package hfdp.ch7;

import cl.mbassale.hfdp.ch7.Turkey;
import cl.mbassale.hfdp.ch7.TurkeyAdapter;
import cl.mbassale.hfdp.ch7.WildTurkey;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TurkeyAdapterTest {

    Turkey turkey;

    @BeforeEach
    void setUp() {
        turkey = new WildTurkey();
    }

    @Test
    void quack() {
        var turkeyAdapter = new TurkeyAdapter(turkey);
        assertDoesNotThrow(turkeyAdapter::quack);
    }

    @Test
    void fly() {
        var turkeyAdapter = new TurkeyAdapter(turkey);
        assertDoesNotThrow(turkeyAdapter::fly);
    }
}