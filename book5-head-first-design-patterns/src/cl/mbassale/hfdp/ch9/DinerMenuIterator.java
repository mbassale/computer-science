package cl.mbassale.hfdp.ch9;

import java.util.Iterator;

public class DinerMenuIterator implements Iterator<MenuItem> {

    MenuItem[] items;
    int position = 0;

    public DinerMenuIterator(MenuItem[] items) {
        this.items = items;
    }

    @Override
    public boolean hasNext() {
        return position < items.length && items[position] != null;
    }

    @Override
    public MenuItem next() {
        return items[position++];
    }

    @Override
    public void remove() {
        throw new UnsupportedOperationException("Can't remove menu items.");
    }
}
