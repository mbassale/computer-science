package cl.mbassale.hfdp.ch9;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class CafeMenu extends Menu {

    public CafeMenu() {
        super("CAFE", "Cafe menu");

        addItem("Veggie Burger and Air Fries", "Veggie burger on a whole wheat bun, lettuce, tomato, and fries", true, 3.99);
        addItem("Soup of the day", "A cup of the soup of the day, with a side salad", false, 3.69);
        addItem("Burrito", "A large burrito, with whole pinto beans, salsa and guacamole", true, 4.29);
    }

    public void addItem(String name, String description, boolean vegetarian, double price) {
        add(new MenuItem(name, description, vegetarian, price));
    }
}
