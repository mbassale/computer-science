import collections
import unittest
from random import choice

Card = collections.namedtuple('Card', ['rank', 'suit'])


class FrenchDeck:
    ranks = [str(n) for n in range(2, 11)] + list('JQKA')
    suits = 'spades diamonds clubs hearts'.split()

    def __init__(self):
        self._cards = [Card(rank, suit) for suit in self.suits for rank in self.ranks]

    def __len__(self):
        return len(self._cards)

    def __getitem__(self, position):
        return self._cards[position]


suits_values = dict(spades=3, hearts=2, diamonds=1, clubs=0)


def spades_high(card: Card):
    rank_value = FrenchDeck.ranks.index(card.rank)
    return rank_value * len(suits_values) + suits_values[card.suit]


class TestFrenchDeck(unittest.TestCase):

    def setUp(self) -> None:
        self.deck = FrenchDeck()

    def assertIsCard(self, card):
        self.assertIsInstance(card, Card)
        self.assertIsNotNone(card.suit)
        self.assertIsNotNone(card.rank)

    def assertHasCards(self, cards):
        for card in cards:
            self.assertIsInstance(card, Card)
            self.assertIsNotNone(card.suit)
            self.assertIsNotNone(card.rank)

    def test_card(self):
        beer_card = Card('7', 'diamonds')
        self.assertEqual('7', beer_card.rank)
        self.assertEqual('diamonds', beer_card.suit)

    def test_deck(self):
        self.assertEqual(52, len(self.deck))

    def test_getitem(self):
        self.assertIsNotNone(self.deck[0])
        self.assertIsNotNone(self.deck[1])
        self.assertEqual('2', self.deck[0].rank)
        self.assertEqual('spades', self.deck[0].suit)
        self.assertEqual('A', self.deck[-1].rank)
        self.assertEqual('hearts', self.deck[-1].suit)

    def test_random_card(self):
        random_card = choice(self.deck)
        self.assertIsNotNone(random_card.rank)
        self.assertIsNotNone(random_card.suit)

    def test_slicing(self):
        cards = self.deck[:3]
        self.assertEqual(3, len(cards))
        self.assertHasCards(cards)
        cards = self.deck[12::13]
        self.assertEqual(4, len(cards))
        self.assertHasCards(cards)

    def test_iterable(self):
        for card in self.deck:
            self.assertIsCard(card)
        for card in reversed(self.deck):
            self.assertIsCard(card)

    def test_in_operator(self):
        self.assertTrue(Card('Q', 'hearts') in self.deck)
        self.assertFalse(Card('7', 'beasts') in self.deck)

    def test_sorted(self):
        sorted_cards = sorted(self.deck, key=spades_high)
        self.assertIsCard(sorted_cards[0])
        self.assertIsCard(sorted_cards[1])
        self.assertIsCard(sorted_cards[-2])
        self.assertIsCard(sorted_cards[-1])

        self.assertEqual(sorted_cards[0].rank, '2')
        self.assertEqual(sorted_cards[0].suit, 'clubs')
        self.assertEqual(sorted_cards[-1].rank, 'A')
        self.assertEqual(sorted_cards[-1].suit, 'spades')


if __name__ == '__main__':
    unittest.main()
