package cl.mbassale.hfdp.ch11.remoteProxy;

public interface State {
    void insertQuarter();

    void ejectQuarter();

    void turnCrank();

    void dispense();
}
