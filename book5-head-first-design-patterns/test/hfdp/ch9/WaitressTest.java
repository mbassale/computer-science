package hfdp.ch9;

import cl.mbassale.hfdp.ch9.CafeMenu;
import cl.mbassale.hfdp.ch9.DinerMenu;
import cl.mbassale.hfdp.ch9.PancakeHouseMenu;
import cl.mbassale.hfdp.ch9.Waitress;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WaitressTest {

    @Test
    void printMenu() {
        PancakeHouseMenu pancakeHouseMenu = new PancakeHouseMenu();
        DinerMenu dinerMenu = new DinerMenu();
        CafeMenu cafeMenu = new CafeMenu();
        Waitress waitress = new Waitress(pancakeHouseMenu, dinerMenu, cafeMenu);
        assertDoesNotThrow(waitress::printMenu);
    }
}