package hfdp.ch12;

import static org.junit.jupiter.api.Assertions.*;

import cl.mbassale.hfdp.ch12.workout.*;
import org.junit.jupiter.api.Test;

public class DuckTest {
    @Test
    void simulate() {
        AbstractDuckFactory duckFactory = new CountingDuckFactory();
        simulate(duckFactory);
    }

    void simulate(AbstractDuckFactory duckFactory) {
        Quackable redheadDuck = duckFactory.createRedheadDuck();
        Quackable duckCall = duckFactory.createDuckCall();
        Quackable rubberDuck = duckFactory.createRubberDuck();
        Quackable gooseDuck = new GooseAdapter(new Goose());

        Flock flockOfDucks = new Flock();
        flockOfDucks.add(redheadDuck);
        flockOfDucks.add(duckCall);
        flockOfDucks.add(rubberDuck);
        flockOfDucks.add(gooseDuck);

        simulate(flockOfDucks);
        assertEquals(3, QuackCounter.getQuacks());


        Flock flockOfMallards = new Flock();
        for (var i = 0; i < 4; i++)
            flockOfMallards.add(duckFactory.createMallardDuck());

        Quackologist quackologist = new Quackologist();
        flockOfMallards.registerObserver(quackologist);
        simulate(flockOfMallards);
        assertEquals(7, QuackCounter.getQuacks());
    }

    void simulate(Quackable duck) {
        assertDoesNotThrow(duck::quack);
    }
}
