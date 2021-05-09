import unittest


class ByteTest(unittest.TestCase):

    def test_binaryarray(self):
        cafe = bytes('café', encoding='utf_8')
        self.assertEqual(b'caf\xc3\xa9', cafe)
        self.assertEqual(99, cafe[0])
        self.assertEqual(b'c', cafe[:1])
        cafe_arr = bytearray(cafe)
        self.assertEqual(bytearray(b'\xa9'), cafe_arr[-1:])


if __name__ == '__main__':
    unittest.main()
