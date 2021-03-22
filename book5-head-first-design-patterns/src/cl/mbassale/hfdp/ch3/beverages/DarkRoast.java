package cl.mbassale.hfdp.ch3.beverages;

import cl.mbassale.hfdp.ch3.Beverage;

public class DarkRoast extends Beverage {

    public DarkRoast() {
        description = "DarkRoast";
    }

    @Override
    public float cost() {
        return 0.99f;
    }
}
