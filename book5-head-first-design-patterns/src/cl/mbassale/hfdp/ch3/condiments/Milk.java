package cl.mbassale.hfdp.ch3.condiments;

import cl.mbassale.hfdp.ch3.Beverage;
import cl.mbassale.hfdp.ch3.CondimentDecorator;

public class Milk extends CondimentDecorator {

    public Milk(Beverage beverage) {
        this.beverage = beverage;
        description = "Milk";
    }

    @Override
    public float cost() {
        return 0.1f + beverage.cost();
    }
}
