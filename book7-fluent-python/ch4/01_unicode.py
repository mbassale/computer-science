import unittest


class UnicodeTest(unittest.TestCase):

    def test_encoding(self):
        s = 'café'
        self.assertEqual(4, len(s))
        b = s.encode('utf8')
        self.assertEqual(b'caf\xc3\xa9', b)
        self.assertEqual(5, len(b))
        c = b.decode('utf8')
        self.assertEqual('café', c)

    def test_errors(self):
        city = 'São Paulo'
        self.assertEqual(b'S\xc3\xa3o Paulo', city.encode('utf_8'))
        self.assertEqual(b'\xff\xfeS\x00\xe3\x00o\x00 \x00P\x00a\x00u\x00l\x00o\x00', city.encode('utf_16'))
        self.assertEqual(b'S\xe3o Paulo', city.encode('iso8859'))
        self.assertRaises(UnicodeEncodeError, lambda: city.encode('cp437'))
        self.assertEqual(b'So Paulo', city.encode('cp437', errors='ignore'))
        self.assertEqual(b'S?o Paulo', city.encode('cp437', errors='replace'))
        self.assertEqual(b'S&#227;o Paulo', city.encode('cp437', errors='xmlcharrefreplace'))

    def test_replacements(self):
        octets = b'Montr\xe9al'
        self.assertEqual('Montréal', octets.decode('cp1252'))
        self.assertEqual('Montrιal', octets.decode('iso8859_7'))
        self.assertEqual('MontrИal', octets.decode('koi8_r'))
        self.assertRaises(UnicodeDecodeError, lambda: octets.decode('utf_8'))
        self.assertEqual('Montr�al', octets.decode('utf_8', errors='replace'))


if __name__ == '__main__':
    unittest.main()
