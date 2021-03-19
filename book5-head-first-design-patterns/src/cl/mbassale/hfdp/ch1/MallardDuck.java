package cl.mbassale.hfdp.ch1;

import cl.mbassale.hfdp.ch1.behavior.FlyWithWings;
import cl.mbassale.hfdp.ch1.behavior.Quack;

public class MallardDuck extends Duck {

    public MallardDuck() {
        quackBehavior = new Quack();
        flyBehavior = new FlyWithWings();
    }

    @Override
    public void display() {
        System.out.println("Mallard display.");
    }
}
