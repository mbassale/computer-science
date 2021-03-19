package cl.mbassale.hfdp.ch1;

import cl.mbassale.hfdp.ch1.behavior.FlyBehavior;
import cl.mbassale.hfdp.ch1.behavior.FlyNoWay;
import cl.mbassale.hfdp.ch1.behavior.MuteQuack;
import cl.mbassale.hfdp.ch1.behavior.QuackBehavior;

public abstract class Duck {
    protected FlyBehavior flyBehavior = new FlyNoWay();
    protected QuackBehavior quackBehavior = new MuteQuack();

    public abstract void display();

    public void swim() {
        System.out.println("Duck swim.");
    }

    public void quack() {
        quackBehavior.quack();
    }

    public void fly() {
        flyBehavior.fly();
    }

    public void setFlyBehavior(FlyBehavior flyBehavior) {
        this.flyBehavior = flyBehavior;
    }

    public void setQuackBehavior(QuackBehavior quackBehavior) {
        this.quackBehavior = quackBehavior;
    }
}
