import collections
import unittest
from collections import abc, defaultdict
import random
from types import MappingProxyType


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
        self.assertEqual(100, len(number_count))

    def test_view(self):
        d = dict(a=10, b=20, c=30)
        values = d.values()
        self.assertEqual(3, len(values))
        self.assertEqual([10, 20, 30], list(values))


class StrKeyDict(collections.UserDict):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.default = kwargs['default'] if 'default' in kwargs else None

    def __missing__(self, key):
        if isinstance(key, str):
            if self.default is not None:
                self[key] = self.default()
                return self[key]
            else:
                raise KeyError(key)
        return self[str(key)]

    def __contains__(self, key):
        return str(key) in self.data

    def __setitem__(self, key, value):
        self.data[str(key)] = value


class UserDictTest(unittest.TestCase):
    def test_defaultdict(self):
        dd = defaultdict(set)
        for i in range(10000):
            random_num = random.randint(1, 100)
            dd[random_num].add(random_num)
        self.assertEqual(100, len(dd))

    def test_subclass_default(self):
        sd = StrKeyDict(default=list)
        self.assertIsInstance(sd[1], list)
        sd[1].append(1)
        sd['1'].append(2)
        self.assertEqual([1, 2], sd[1])


class CounterTest(unittest.TestCase):

    def test_counter(self):
        ct = collections.Counter('abracadabra')
        self.assertEqual({'a': 5, 'b': 2, 'r': 2, 'c': 1, 'd': 1}, dict(ct))

        ct.update('aaaaazzz')
        self.assertEqual({'a': 10, 'z': 3, 'b': 2, 'r': 2, 'c': 1, 'd': 1}, dict(ct))

        self.assertEqual([('a', 10), ('z', 3), ('b', 2)], ct.most_common(3))


class MappingProxyTest(unittest.TestCase):

    def test_proxy(self):
        d = {1: 'A'}
        d_proxy = MappingProxyType(d)
        self.assertEqual('A', d_proxy[1])

        def set_proxy():
            d_proxy[2] = 'X'

        self.assertRaises(TypeError, set_proxy)

        d[2] = 'B'
        self.assertEqual('B', d_proxy[2])


if __name__ == '__main__':
    unittest.main()
