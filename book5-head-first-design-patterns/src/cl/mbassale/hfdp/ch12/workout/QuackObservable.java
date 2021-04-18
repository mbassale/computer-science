package cl.mbassale.hfdp.ch12.workout;

public interface QuackObservable {
    void registerObserver(Observer observer);
    void notifyObservers();
}
