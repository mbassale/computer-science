package cl.mbassale.cleanCoders.sort;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.MatcherAssert.assertThat;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class SortTest {

    private List<Integer> intList(Integer... ints) {
        return Arrays.asList(ints);
    }

    private void assertSorted(List<Integer> unsorted, List<Integer> sorted) {
        assertThat(sort(unsorted), is(sorted));
    }

    @Test
    public void testSorts() {
        assertSorted(intList(), intList());
        assertSorted(intList(1), intList(1));
        assertSorted(intList(2, 1), intList(1, 2));
        assertSorted(intList(1, 3, 2), intList(1, 2, 3));
        assertSorted(intList(3, 2, 1), intList(1, 2, 3));
        sortBigList(25000);
    }

    private void sortBigList(int n) {
        List<Integer> unsorted = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            unsorted.add((int)(Math.random() * 1000.0));
        List<Integer> sorted = sort(unsorted);
        for (int i = 0; i < n - 1; i++)
            assertTrue(sorted.get(i) <= sorted.get(i + 1));
    }

    private List<Integer> sort(List<Integer> list) {
        for (int size = list.size(); size >= 0; size--)
            for (int index = 0; size > index + 1; index++)
                if (outOfOrder(list, index))
                    swap(list, index);
        return list;
    }

    private boolean outOfOrder(List<Integer> list, int index) {
        return list.get(index) > list.get(index + 1);
    }

    private void swap(List<Integer> list, int index) {
        var temp = list.get(index);
        list.set(index, list.get(index + 1));
        list.set(index + 1, temp);
    }
}
