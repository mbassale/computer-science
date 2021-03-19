package cl.mbassale.hfdp.ch1.behavior;

public class Quack implements QuackBehavior {
    @Override
    public void quack() {
        System.out.println("Quack.");
    }
}
