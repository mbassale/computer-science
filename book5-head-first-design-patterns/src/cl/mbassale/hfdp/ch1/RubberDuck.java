package cl.mbassale.hfdp.ch1;

import cl.mbassale.hfdp.ch1.behavior.FlyNoWay;
import cl.mbassale.hfdp.ch1.behavior.Squeak;

public class RubberDuck extends Duck {

    public RubberDuck() {
        quackBehavior = new Squeak();
        flyBehavior = new FlyNoWay();
    }

    @Override
    public void display() {
        System.out.println("RubberDuck display.");
    }
}
