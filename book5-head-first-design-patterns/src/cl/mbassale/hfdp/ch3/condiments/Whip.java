package cl.mbassale.hfdp.ch3.condiments;

import cl.mbassale.hfdp.ch3.Beverage;
import cl.mbassale.hfdp.ch3.CondimentDecorator;

public class Whip extends CondimentDecorator {

    public Whip(Beverage beverage) {
        this.beverage = beverage;
        description = "Whip";
    }

    @Override
    public float cost() {
        return 0.10f + beverage.cost();
    }
}
