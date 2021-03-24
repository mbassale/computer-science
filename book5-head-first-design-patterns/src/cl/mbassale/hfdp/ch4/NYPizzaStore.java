package cl.mbassale.hfdp.ch4;

import cl.mbassale.hfdp.ch4.ingredients.NYPizzaIngredientFactory;
import cl.mbassale.hfdp.ch4.ingredients.PizzaIngredientFactory;

public class NYPizzaStore extends PizzaStore {
    @Override
    protected Pizza createPizza(String type) {
        PizzaIngredientFactory ingredientFactory = new NYPizzaIngredientFactory();
        return switch (type) {
            case "cheese" -> new CheesePizza(ingredientFactory);
            case "veggie" -> new VeggiePizza();
            case "clam" -> new ClamPizza(ingredientFactory);
            case "pepperoni" -> new PepperoniPizza();
            default -> throw new IllegalStateException("Unexpected value: " + type);
        };
    }
}
