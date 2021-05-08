import unittest
from collections import abc
import random


class DictTest(unittest.TestCase):

    def test_isinstance(self):
        d = {}
        self.assertTrue(isinstance(d, abc.Mapping))
        self.assertTrue(isinstance(d, abc.MutableMapping))

    def test_hashable(self):
        tt = (1, 2, (3, 4))
        self.assertTrue(hash(tt))

        tl = (1, 2, [3, 4])
        self.assertRaises(TypeError, lambda: hash(tl))

        tf = (1, 2, frozenset([30, 40]))
        self.assertTrue(hash(tf))

    def test_build(self):
        a = dict(one=1, two=2, three=3)
        b = {'three': 3, 'two': 2, 'one': 1}
        c = dict([('two', 2), ('one', 1), ('three', 3)])
        d = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
        e = dict({'three': 3, 'one': 1, 'two': 2})
        self.assertTrue(a == b == c == d == e)

    def test_dictcomp(self):
        dial_codes = [
            (880, 'Bangladesh'),
            (55, 'Brazil'),
            (86, 'China'),
            (91, 'India'),
            (62, 'Indonesia'),
            (81, 'Japan'),
            (234, 'Nigeria'),
            (92, 'Pakistan'),
            (7, 'Russia'),
            (1, 'United States'),
        ]
        country_dial = {country: code for code, country in dial_codes}
        self.assertEqual(len(dial_codes), len(country_dial))
        self.assertEqual([880, 55, 86, 91, 62, 81, 234, 92, 7, 1], list(country_dial.values()))

    def test_setdefault(self):
        number_count = {}
        for i in range(10000):
            random_num = random.randint(1, 100)
            number_count.setdefault(random_num, []).append(i)
        self.assertTrue(len(number_count), 100)


if __name__ == '__main__':
    unittest.main()
