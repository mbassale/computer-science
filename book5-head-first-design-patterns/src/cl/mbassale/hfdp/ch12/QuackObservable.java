package cl.mbassale.hfdp.ch12;

public interface QuackObservable {
    void registerObserver(Observer observer);
    void notifyObservers();
}
