package cl.mbassale.hfdp.ch3.condiments;

import cl.mbassale.hfdp.ch3.Beverage;
import cl.mbassale.hfdp.ch3.CondimentDecorator;

public class Mocha extends CondimentDecorator {

    public Mocha(Beverage beverage) {
        this.beverage = beverage;
        description = "Mocha";
    }

    @Override
    public float cost() {
        return 0.2f + beverage.cost();
    }
}
