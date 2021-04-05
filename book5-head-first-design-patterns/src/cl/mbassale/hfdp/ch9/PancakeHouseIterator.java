package cl.mbassale.hfdp.ch9;

import java.util.ArrayList;

public class PancakeHouseIterator implements Iterator {
    ArrayList<MenuItem> menuItems;
    int position;

    public PancakeHouseIterator(ArrayList<MenuItem> menuItems) {
        this.menuItems = menuItems;
    }

    @Override
    public boolean hasNext() {
        return position < menuItems.size();
    }

    @Override
    public MenuItem next() {
        return menuItems.get(position++);
    }
}
