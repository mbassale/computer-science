package hfdp.ch4;

import cl.mbassale.hfdp.ch4.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SimplePizzaFactoryTest {

    SimplePizzaFactory simplePizzaFactory;

    @BeforeEach
    void setUp() {
        simplePizzaFactory = new SimplePizzaFactory();
    }

    @Test
    void createPizza() {
        assertTrue(simplePizzaFactory.createPizza("cheese") instanceof CheesePizza);
        assertTrue(simplePizzaFactory.createPizza("pepperoni") instanceof PepperoniPizza);
        assertTrue(simplePizzaFactory.createPizza("clam") instanceof ClamPizza);
        assertTrue(simplePizzaFactory.createPizza("veggie") instanceof VeggiePizza);
    }
}