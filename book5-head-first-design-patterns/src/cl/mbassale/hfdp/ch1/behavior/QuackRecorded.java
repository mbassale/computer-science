package cl.mbassale.hfdp.ch1.behavior;

public class QuackRecorded implements QuackBehavior {
    @Override
    public void quack() {
        System.out.println("Quacking from a recording.");
    }
}
