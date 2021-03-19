package cl.mbassale.hfdp.ch1;

import cl.mbassale.hfdp.ch1.behavior.QuackBehavior;
import cl.mbassale.hfdp.ch1.behavior.QuackRecorded;

public class DuckCallDevice {

    QuackBehavior quackBehavior = new QuackRecorded();

    public void quack() {
        quackBehavior.quack();
    }
}
