package cl.mbassale.hfdp.ch9;

import java.util.Iterator;

public class DinerMenu extends Menu {

    public DinerMenu() {
        super("DINER", "Diner menu.");

        addItem("Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
        addItem("BLT", "Bacon with lettuce and tomato on whole wheat", false, 2.99);
        addItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
        addItem("Hotdog", "A hot dog, with sauerkraut, relish, onions, topped with cheese", false, 3.05);
    }

    public void addItem(String name, String description, boolean vegetarian, double price) {
        add(new MenuItem(name, description, vegetarian, price));
    }
}
