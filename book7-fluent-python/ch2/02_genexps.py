import unittest
import array


class GeneratorExpressionsTest(unittest.TestCase):

    def test1(self):
        char_codes = (36, 162, 163, 165, 8364, 164)
        symbols = '$¢£¥€¤'
        tuple1 = tuple(ord(symbol) for symbol in symbols)
        self.assertEqual(char_codes, tuple1)

        array1 = array.array('I', (ord(symbol) for symbol in symbols))
        self.assertEqual(char_codes, tuple(array1))

    def test2(self):
        colors = ['black', 'white']
        sizes = ['S', 'M', 'L']
        tshirt_prints = []
        for tshirt in ('%s %s' % (c, s) for c in colors for s in sizes):
            tshirt_prints.append(tshirt)
        self.assertEqual(6, len(tshirt_prints))
        self.assertEqual('black S', tshirt_prints[0])
        self.assertEqual('white L', tshirt_prints[-1])


if __name__ == '__main__':
    unittest.main()
