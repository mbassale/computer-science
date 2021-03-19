package cl.mbassale.hfdp.ch1;

import cl.mbassale.hfdp.ch1.behavior.FlyNoWay;
import cl.mbassale.hfdp.ch1.behavior.MuteQuack;

public class DecoyDuck extends Duck {

    public DecoyDuck() {
        quackBehavior = new MuteQuack();
        flyBehavior = new FlyNoWay();
    }

    @Override
    public void display() {
        System.out.println("Decoy display.");
    }
}
