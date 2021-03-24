package cl.mbassale.hfdp.ch4;

import cl.mbassale.hfdp.ch4.ingredients.PizzaIngredientFactory;

public class SimplePizzaFactory {

    public Pizza createPizza(String type, PizzaIngredientFactory ingredientFactory) {
        return switch (type) {
            case "cheese" -> new CheesePizza(ingredientFactory);
            case "pepperoni" -> new PepperoniPizza();
            case "clam" -> new ClamPizza(ingredientFactory);
            case "veggie" -> new VeggiePizza();
            default -> null;
        };
    }

}
