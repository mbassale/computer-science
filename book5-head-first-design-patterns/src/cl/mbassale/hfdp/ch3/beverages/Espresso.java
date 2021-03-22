package cl.mbassale.hfdp.ch3.beverages;

import cl.mbassale.hfdp.ch3.Beverage;

public class Espresso extends Beverage {

    public Espresso() {
        description = "Espresso";
    }

    @Override
    public float cost() {
        return 0.89f;
    }
}
