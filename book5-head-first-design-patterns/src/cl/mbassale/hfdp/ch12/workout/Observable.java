package cl.mbassale.hfdp.ch12.workout;

import java.util.ArrayList;
import java.util.List;

public class Observable implements QuackObservable {
    List<Observer> observers = new ArrayList<>();
    QuackObservable duck;

    public Observable(QuackObservable duck) {
        this.duck = duck;
    }

    @Override
    public void registerObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void notifyObservers() {
        for (var observer : observers) {
            observer.update(duck);
        }
    }
}
