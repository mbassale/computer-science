package cl.mbassale.hfdp.ch1;

import cl.mbassale.hfdp.ch1.behavior.FlyWithWings;
import cl.mbassale.hfdp.ch1.behavior.Quack;

public class RedheadDuck extends Duck {

    public RedheadDuck() {
        quackBehavior = new Quack();
        flyBehavior = new FlyWithWings();
    }

    @Override
    public void display() {
        System.out.println("Redhead display.");
    }
}
