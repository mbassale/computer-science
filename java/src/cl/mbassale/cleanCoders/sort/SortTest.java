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
        assertSorted(intList(2, 1, 3), intList(1, 2, 3));
        assertSorted(intList(2, 3, 1), intList(1, 2, 3));
        assertSorted(intList(1, 3, 2), intList(1, 2, 3));
        assertSorted(intList(3, 2, 1), intList(1, 2, 3));
        assertSorted(intList(3, 2, 2, 1), intList(1, 2, 2, 3));
        sortBigList(50000);
    }

    private void sortBigList(int n) {
        List<Integer> unsorted = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            unsorted.add((int) (Math.random() * 1000.0));
        List<Integer> sorted = sort(unsorted);
        for (int i = 0; i < n - 1; i++)
            assertTrue(sorted.get(i) <= sorted.get(i + 1));
    }

    private List<Integer> sort(List<Integer> list) {
        List<Integer> sorted = new ArrayList<>();
        if (list.size() <= 1)
            return list;
        else if (list.size() == 2) {
            return Arrays.asList(Math.min(list.get(0), list.get(1)), Math.max(list.get(0), list.get(1)));
        } else {
            List<Integer> leftElements = new ArrayList<>();
            int middle = list.get(0);
            List<Integer> rightElements = new ArrayList<>();
            for (int i : list.subList(1, list.size())) {
                if (i > middle)
                    rightElements.add(i);
                else
                    leftElements.add(i);
            }
            sorted.addAll(sort(leftElements));
            sorted.add(middle);
            sorted.addAll(sort(rightElements));
        }
        return sorted;
    }

}
