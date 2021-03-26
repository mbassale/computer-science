package cl.mbassale.hfdp.ch7;

public class WildTurkey implements Turkey {
    @Override
    public void gobble() {
        System.out.println("Gobble gobble");
    }

    @Override
    public void fly() {
        System.out.println("Fly, but short distance");
    }
}
