package cl.mbassale.hfdp.ch3.beverages;

import cl.mbassale.hfdp.ch3.Beverage;

public class HouseBlend extends Beverage {

    public HouseBlend() {
        description = "HouseBlend";
    }

    @Override
    public float cost() {
        return 0.89f;
    }
}
