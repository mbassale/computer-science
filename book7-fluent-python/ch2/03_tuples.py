import unittest
import os


class TupleRecords(unittest.TestCase):

    def test_star_operator(self):
        t = (20, 8)
        q, r = divmod(*t)
        self.assertEqual(2, q)
        self.assertEqual(4, r)

    def test_return_multiple(self):
        _, filename = os.path.split('/home/mbassale/.ssh/id_rsa.pub')
        self.assertEqual('id_rsa.pub', filename)

    def test_unpack_excess_items(self):
        a, b, *rest = range(5)
        self.assertEqual(0, a)
        self.assertEqual(1, b)
        self.assertEqual([2, 3, 4], rest)

        a, b, *rest = range(3)
        self.assertEqual(0, a)
        self.assertEqual(1, b)
        self.assertEqual([2], rest)

        a, b, *rest = range(2)
        self.assertEqual(0, a)
        self.assertEqual(1, b)
        self.assertEqual([], rest)

        a, *body, c, d = range(5)
        self.assertEqual(0, a)
        self.assertEqual([1, 2], body)
        self.assertEqual(3, c)
        self.assertEqual(4, d)

        *prefix, c, d = range(5)
        self.assertEqual([0, 1, 2], prefix)
        self.assertEqual(3, c)
        self.assertEqual(4, d)

    def test_unpack_nested_struct(self):
        metro_areas = [
            ('Tokyo', 'JP', 36.933, (35.689722, 139.691667)),
            ('Delhi NCR', 'IN', 21.935, (28.613889, 77.208889)),
            ('Mexico City', 'MX', 20.142, (19.433333, -99.133333)),
            ('New York-Newark', 'US', 20.104, (40.808611, -74.020386)),
            ('Sao Paulo', 'BR', 19.649, (-23.547778, -46.635833)),
        ]

        for name, cc, pop, (latitude, longitude) in metro_areas:
            self.assertIsInstance(name, str)
            self.assertIn(name, ['Tokyo', 'Delhi NCR', 'Mexico City', 'New York-Newark', 'Sao Paulo'])
            self.assertIn(cc, ['JP', 'IN', 'MX', 'US', 'BR'])
            self.assertTrue(pop > 0)
            self.assertTrue(-180 <= latitude <= 180)
            self.assertTrue(-180 <= longitude <= 180)


if __name__ == '__main__':
    unittest.main()
