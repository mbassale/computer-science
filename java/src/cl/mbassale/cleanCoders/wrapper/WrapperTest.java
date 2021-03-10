package cl.mbassale.cleanCoders.wrapper;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class WrapperTest {

    private void assertWraps(String s, int width, String expected) {
        assertEquals(expected, wrap(s, width));
    }

    @Test
    public void shouldWrap() throws Exception {
        assertWraps(null, 1, "");
        assertWraps("", 1, "");
        assertWraps("x", 1, "x");
        assertWraps("xx", 1, "x\nx");
        assertWraps("xxx", 1, "x\nx\nx");
        assertWraps("x x", 1, "x\nx");
    }

    private String wrap(String s, int width) {
        if (s == null) return "";
        if (s.length() <= width) return s;
        else {
            var breakPoint = s.lastIndexOf(" ");
            if (breakPoint == -1) breakPoint = width;
            return s.substring(0, breakPoint) + "\n" + wrap(s.substring(breakPoint).trim(), width);
        }
    }

}
