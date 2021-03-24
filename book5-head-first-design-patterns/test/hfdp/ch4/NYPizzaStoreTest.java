package hfdp.ch4;

import cl.mbassale.hfdp.ch4.CheesePizza;
import cl.mbassale.hfdp.ch4.NYPizzaStore;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;

class NYPizzaStoreTest {

    NYPizzaStore nyPizzaStore;

    @BeforeEach
    void setUp() {
        nyPizzaStore = new NYPizzaStore();
    }

    @Test
    void createPizza() {
        assertTrue(nyPizzaStore.orderPizza("cheese") instanceof CheesePizza);
    }
}