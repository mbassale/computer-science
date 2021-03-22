package cl.mbassale.hfdp.ch3;

public abstract class Beverage {

    protected String description;

    public String getDescription() {
        return description;
    }

    public abstract float cost();
}
