from array import array
import random
import unittest


class TestArrays(unittest.TestCase):

    def test_arrays(self):
        floats = array('d', (random.random() for i in range(10 ** 7)))
        first_float = floats[0]
        last_float = floats[-1]
        random_index = random.randint(1, len(floats) - 2)
        random_float = floats[random_index]

        fp = open('floats.bin', 'wb')
        floats.tofile(fp)
        fp.close()
        del floats

        floats2 = array('d')
        fp = open('floats.bin', 'rb')
        floats2.fromfile(fp, 10 ** 7)
        fp.close()

        self.assertEqual(first_float, floats2[0])
        self.assertEqual(last_float, floats2[-1])
        self.assertEqual(random_float, floats2[random_index])


if __name__ == '__main__':
    unittest.main()
