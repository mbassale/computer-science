import unittest


class SetTest(unittest.TestCase):

    def test_init(self):
        l = ['spam', 'spam', 'eggs', 'spam', 'bacon', 'eggs']
        s = set(l)
        self.assertEqual(sorted(['eggs', 'spam', 'bacon']), sorted(list(s)))

    def test_key_preservation(self):
        l = ['spam', 'spam', 'eggs', 'spam', 'bacon', 'eggs']
        self.assertEqual(['spam', 'eggs', 'bacon'], list(dict.fromkeys(l).keys()))

    def test_literal(self):
        s = {1, 2, 3, 4}
        self.assertEqual([1, 2, 3, 4], sorted(list(s)))

    def test_dict_keys(self):
        d1 = dict(a=1, b=2, c=3, d=4)
        d2 = dict(b=20, d=40, e=50)
        self.assertEqual({'b', 'd'}, d1.keys() & d2.keys())


if __name__ == '__main__':
    unittest.main()
