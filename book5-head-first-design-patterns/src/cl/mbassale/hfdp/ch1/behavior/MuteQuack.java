package cl.mbassale.hfdp.ch1.behavior;

public class MuteQuack implements QuackBehavior {
    @Override
    public void quack() {
        System.out.println("No quack.");
    }
}
