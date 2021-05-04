import unittest


class TestList(unittest.TestCase):

    def test_listcomps(self):
        char_codes = [36, 162, 163, 165, 8364, 164]
        symbols = '$¢£¥€¤'
        codes = []
        for symbol in symbols:
            codes.append(ord(symbol))
        self.assertEqual(char_codes, codes)

        codes = [ord(symbol) for symbol in symbols]
        self.assertEqual(char_codes, codes)

        beyond_ascii = [ord(s) for s in symbols if ord(s) > 127]
        self.assertEqual(char_codes[1:], beyond_ascii)

        beyond_ascii = list(filter(lambda c: c > 127, map(ord, symbols)))
        self.assertEqual(char_codes[1:], beyond_ascii)

    def test_cartesian_product(self):
        colors = ['black', 'white']
        sizes = ['S', 'M', 'L']
        t_shirts = [(color, size) for color in colors for size in sizes]
        self.assertEqual(('black', 'S'), t_shirts[0])
        self.assertEqual(('white', 'L'), t_shirts[-1])
        self.assertEqual(6, len(t_shirts))


if __name__ == '__main__':
    unittest.main()
