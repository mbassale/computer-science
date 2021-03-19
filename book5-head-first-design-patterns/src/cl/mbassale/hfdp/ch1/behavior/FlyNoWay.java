package cl.mbassale.hfdp.ch1.behavior;

public class FlyNoWay implements FlyBehavior {
    @Override
    public void fly() {
        System.out.println("No fly.");
    }
}
