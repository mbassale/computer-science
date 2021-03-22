package cl.mbassale.hfdp.ch3.beverages;

import cl.mbassale.hfdp.ch3.Beverage;

public class Decaf extends Beverage {

    public Decaf() {
        description = "Decaf";
    }

    @Override
    public float cost() {
        return 1.05f;
    }
}
