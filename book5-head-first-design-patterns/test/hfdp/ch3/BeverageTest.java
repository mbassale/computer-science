package hfdp.ch3;

import cl.mbassale.hfdp.ch3.beverages.DarkRoast;
import cl.mbassale.hfdp.ch3.beverages.HouseBlend;
import cl.mbassale.hfdp.ch3.condiments.Mocha;
import cl.mbassale.hfdp.ch3.condiments.Soy;
import cl.mbassale.hfdp.ch3.condiments.Whip;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class BeverageTest {

    @Test
    public void testBeverages() {
        var beverage = new Whip(new Mocha(new Mocha(new DarkRoast())));
        assertEquals(1.49f, beverage.cost(), 0.05);

        beverage = new Whip(new Mocha(new Soy(new HouseBlend())));
        assertEquals(1.34, beverage.cost(), 0.05);
    }

}
