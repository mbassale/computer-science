package cl.mbassale.hfdp.ch4;

public class ChicagoPizzaStore extends PizzaStore {
    @Override
    protected Pizza createPizza(String type) {
        return switch (type) {
            case "cheese" -> new ChicagoStyleCheesePizza();
            case "veggie" -> new VeggiePizza();
            case "clam" -> new ClamPizza();
            case "pepperoni" -> new PepperoniPizza();
            default -> throw new IllegalStateException("Unexpected value: " + type);
        };
    }
}
