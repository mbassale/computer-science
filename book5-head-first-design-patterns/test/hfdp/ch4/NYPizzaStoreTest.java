package hfdp.ch4;

import cl.mbassale.hfdp.ch4.NYPizzaStore;
import cl.mbassale.hfdp.ch4.NYStyleCheesePizza;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NYPizzaStoreTest {

    NYPizzaStore nyPizzaStore;

    @BeforeEach
    void setUp() {
        nyPizzaStore = new NYPizzaStore();
    }

    @Test
    void createPizza() {
        assertTrue(nyPizzaStore.orderPizza("cheese") instanceof NYStyleCheesePizza);
    }
}