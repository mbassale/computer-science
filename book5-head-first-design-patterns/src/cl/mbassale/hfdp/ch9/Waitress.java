package cl.mbassale.hfdp.ch9;

import java.util.Iterator;
import java.util.List;

public class Waitress {
    MenuComponent allMenus;

    public Waitress(MenuComponent allMenus) {
        this.allMenus = allMenus;
    }

    public void printMenu() {
        allMenus.print();
    }
}
