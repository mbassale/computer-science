package cl.mbassale.hfdp.ch11;

public interface State {
    void insertQuarter();

    void ejectQuarter();

    void turnCrank();

    void dispense();
}
