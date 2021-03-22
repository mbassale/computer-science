package cl.mbassale.hfdp.ch3.condiments;

import cl.mbassale.hfdp.ch3.Beverage;
import cl.mbassale.hfdp.ch3.CondimentDecorator;

public class Soy extends CondimentDecorator {

    public Soy(Beverage beverage) {
        this.beverage = beverage;
        description = "Soy";
    }

    @Override
    public float cost() {
        return 0.15f + beverage.cost();
    }
}
