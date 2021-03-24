package hfdp.ch4;

import cl.mbassale.hfdp.ch4.CheesePizza;
import cl.mbassale.hfdp.ch4.ChicagoPizzaStore;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ChicagoPizzaStoreTest {

    ChicagoPizzaStore chicagoPizzaStore;

    @BeforeEach
    void setUp() {
        chicagoPizzaStore = new ChicagoPizzaStore();
    }

    @Test
    void createPizza() {
        assertTrue(chicagoPizzaStore.orderPizza("cheese") instanceof CheesePizza);
    }
}