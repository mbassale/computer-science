package hfdp.ch4;

import cl.mbassale.hfdp.ch4.*;
import cl.mbassale.hfdp.ch4.ingredients.NYPizzaIngredientFactory;
import cl.mbassale.hfdp.ch4.ingredients.PizzaIngredientFactory;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;

class SimplePizzaFactoryTest {

    SimplePizzaFactory simplePizzaFactory;
    PizzaIngredientFactory ingredientFactory;

    @BeforeEach
    void setUp() {
        simplePizzaFactory = new SimplePizzaFactory();
        ingredientFactory = new NYPizzaIngredientFactory();
    }

    @Test
    void createPizza() {
        assertTrue(simplePizzaFactory.createPizza("cheese", ingredientFactory) instanceof CheesePizza);
        assertTrue(simplePizzaFactory.createPizza("pepperoni", ingredientFactory) instanceof PepperoniPizza);
        assertTrue(simplePizzaFactory.createPizza("clam", ingredientFactory) instanceof ClamPizza);
        assertTrue(simplePizzaFactory.createPizza("veggie", ingredientFactory) instanceof VeggiePizza);
    }
}